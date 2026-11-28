"""
Train-related API endpoints
"""
from fastapi import APIRouter, Depends, HTTPException, Query
from sqlalchemy.orm import Session
from typing import List, Optional
from pydantic import BaseModel
from app.database import get_db
from app.models import Train, Station, TrainStop
from app.services.rag_service import search_trains_by_route, rag_service

router = APIRouter(prefix="/trains", tags=["trains"])

class StationResponse(BaseModel):
    id: int
    name_ar: str
    name_en: str
    sequence_order: int

    class Config:
        from_attributes = True

class TrainStopResponse(BaseModel):
    station_id: int
    station_name_ar: str
    station_name_en: str
    time: Optional[str]

class TrainScheduleResponse(BaseModel):
    train_id: int
    train_number: str
    train_type: str
    direction: str
    stops: List[TrainStopResponse]

class ClassAvailability(BaseModel):
    type: str
    price: float

class TrainSearchResult(BaseModel):
    train_id: int
    train_number: str
    train_type: str
    departure_time: Optional[str]
    arrival_time: Optional[str]
    available_classes: List[ClassAvailability]
    direction: str

@router.get("/stations", response_model=List[StationResponse])
def get_all_stations(db: Session = Depends(get_db)):
    """Get all stations ordered by sequence"""
    stations = db.query(Station).order_by(Station.sequence_order).all()
    return stations

@router.get("/search", response_model=List[TrainSearchResult])
def search_trains(
    from_station: str = Query(..., description="Starting station name (English or Arabic)"),
    to_station: str = Query(..., description="Destination station name (English or Arabic)"),
    db: Session = Depends(get_db)
):
    """
    Search for trains between two stations

    Returns trains that stop at both stations with available classes and times
    """
    results = search_trains_by_route(db, from_station, to_station)

    if not results:
        raise HTTPException(
            status_code=404,
            detail=f"No trains found from {from_station} to {to_station}"
        )

    return results

@router.get("/{train_number}/schedule", response_model=TrainScheduleResponse)
def get_train_schedule(
    train_number: str,
    direction: str = Query(..., description="Direction: CAIRO_ALEX or ALEX_CAIRO"),
    db: Session = Depends(get_db)
):
    """Get full schedule for a specific train"""
    train = db.query(Train).filter(Train.train_number == train_number).first()

    if not train:
        raise HTTPException(status_code=404, detail="Train not found")

    # Get stops for the specified direction
    stops = db.query(TrainStop).filter(
        TrainStop.train_id == train.id,
        TrainStop.direction == direction
    ).join(Station).order_by(Station.sequence_order).all()

    stop_responses = [
        TrainStopResponse(
            station_id=stop.station.id,
            station_name_ar=stop.station.name_ar,
            station_name_en=stop.station.name_en,
            time=stop.time
        )
        for stop in stops
    ]

    return TrainScheduleResponse(
        train_id=train.id,
        train_number=train.train_number,
        train_type=train.train_type,
        direction=direction,
        stops=stop_responses
    )

@router.get("/semantic-search")
def semantic_search(
    query: str = Query(..., description="Natural language query"),
    n_results: int = Query(5, description="Number of results"),
    db: Session = Depends(get_db)
):
    """
    Search trains using natural language (RAG-powered)

    Example queries:
    - "trains from Cairo to Alexandria in the morning"
    - "cheapest train to Alexandria"
    - "first class trains departing after 6am"
    """
    results = rag_service.search_trains(query, n_results=n_results)

    if not results:
        raise HTTPException(
            status_code=404,
            detail="No trains found matching your query"
        )

    return {"query": query, "results": results}