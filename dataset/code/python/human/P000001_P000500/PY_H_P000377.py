"""Vehicle registry endpoints.

Route order matters: the literal paths (/stats, /search, /bulk-status) are
declared before /{vin}, otherwise FastAPI would match "stats" as a VIN.
"""

from __future__ import annotations

import logging

from fastapi import APIRouter, Depends, HTTPException, Path, Query, status

from app.dependencies import get_telemetry_service, get_vehicle_service
from app.models.telemetry import VehicleSummary
from app.models.vehicle import (
    BulkStatusResult,
    BulkStatusUpdate,
    FleetType,
    Manufacturer,
    RegistrationStatus,
    Vehicle,
    VehicleCreate,
    VehicleStats,
    VehicleUpdate,
)
from app.services.telemetry_service import TelemetryService
from app.services.vehicle_service import VehicleAlreadyExists, VehicleService

logger = logging.getLogger(__name__)

router = APIRouter(prefix="/vehicles", tags=["vehicles"])

VinPath = Path(..., description="17 character Vehicle Identification Number")


@router.post(
    "",
    response_model=Vehicle,
    status_code=status.HTTP_201_CREATED,
    summary="Register a vehicle",
)
async def create_vehicle(
    payload: VehicleCreate,
    service: VehicleService = Depends(get_vehicle_service),
) -> Vehicle:
    """Add a vehicle to the fleet. The VIN must be unique."""
    try:
        return await service.create(payload)
    except VehicleAlreadyExists as exc:
        raise HTTPException(status_code=status.HTTP_409_CONFLICT, detail=str(exc)) from exc


@router.get("", response_model=list[Vehicle], summary="List vehicles")
async def list_vehicles(
    fleet_id: FleetType | None = Query(None, description="Filter by fleet"),
    registration_status: RegistrationStatus | None = Query(
        None, alias="status", description="Filter by registration status"
    ),
    manufacturer: Manufacturer | None = Query(None, description="Filter by manufacturer"),
    limit: int = Query(100, ge=1, le=1000),
    offset: int = Query(0, ge=0),
    service: VehicleService = Depends(get_vehicle_service),
) -> list[Vehicle]:
    """List vehicles, most recently registered first."""
    return service.list(
        fleet_id=fleet_id.value if fleet_id else None,
        status=registration_status.value if registration_status else None,
        manufacturer=manufacturer.value if manufacturer else None,
        limit=limit,
        offset=offset,
    )


@router.get("/stats", response_model=VehicleStats, summary="Fleet composition")
async def vehicle_stats(
    service: VehicleService = Depends(get_vehicle_service),
) -> VehicleStats:
    """Vehicle counts by registration status, fleet and manufacturer."""
    return service.stats()


@router.get("/search", response_model=list[Vehicle], summary="Search vehicles")
async def search_vehicles(
    q: str = Query(..., min_length=1, description="Matched against VIN, model, owner, operator"),
    limit: int = Query(100, ge=1, le=1000),
    service: VehicleService = Depends(get_vehicle_service),
) -> list[Vehicle]:
    """Case-insensitive substring search across the registry."""
    return service.search(q, limit=limit)


@router.put("/bulk-status", response_model=BulkStatusResult, summary="Bulk status update")
async def bulk_status_update(
    payload: BulkStatusUpdate,
    service: VehicleService = Depends(get_vehicle_service),
) -> BulkStatusResult:
    """Set one registration status across many VINs.

    Unknown VINs are reported as `false` in the result rather than failing the
    whole request.
    """
    results = await service.bulk_update_status(payload.vins, payload.status)
    return BulkStatusResult(
        requested=len(payload.vins),
        updated=sum(1 for ok in results.values() if ok),
        results=results,
    )


@router.get("/{vin}", response_model=Vehicle, summary="Get a vehicle")
async def get_vehicle(
    vin: str = VinPath,
    service: VehicleService = Depends(get_vehicle_service),
) -> Vehicle:
    vehicle = service.get(vin)
    if not vehicle:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Vehicle not found")
    return vehicle


@router.get(
    "/{vin}/summary",
    response_model=VehicleSummary,
    summary="Vehicle detail with recent telemetry",
)
async def vehicle_summary(
    vin: str = VinPath,
    service: TelemetryService = Depends(get_telemetry_service),
) -> VehicleSummary:
    """The vehicle record, its latest reading and 24 hour statistics."""
    summary = service.vehicle_summary(vin)
    if not summary:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Vehicle not found")
    return summary


@router.put("/{vin}", response_model=Vehicle, summary="Update a vehicle")
async def update_vehicle(
    payload: VehicleUpdate,
    vin: str = VinPath,
    service: VehicleService = Depends(get_vehicle_service),
) -> Vehicle:
    """Apply a partial update. Fields left out of the body are unchanged."""
    vehicle = await service.update(vin, payload)
    if not vehicle:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Vehicle not found")
    return vehicle


@router.delete(
    "/{vin}",
    response_model=None,
    status_code=status.HTTP_204_NO_CONTENT,
    summary="Delete a vehicle",
)
async def delete_vehicle(
    vin: str = VinPath,
    service: VehicleService = Depends(get_vehicle_service),
    telemetry: TelemetryService = Depends(get_telemetry_service),
) -> None:
    """Remove a vehicle and every telemetry reading it recorded.

    Alerts are kept so the fleet's history stays auditable.
    """
    deleted = await service.delete(vin)
    if not deleted:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="Vehicle not found")
    await telemetry.delete_vehicle_telemetry(vin.replace(" ", "").upper())
