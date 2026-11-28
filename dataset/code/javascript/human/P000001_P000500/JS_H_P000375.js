import express from 'express';
import Patient from '../models/Patient.js';
import { authenticate } from '../middleware/auth.js';
import { requirePermission } from '../middleware/rbac.js';
import { auditCreate, auditUpdate, auditDelete } from '../middleware/auditLog.js';
import { asyncHandler } from '../middleware/errorHandler.js';
import { validateSchema } from '../utils/validators.js';
import { createPatientSchema, updatePatientSchema } from '../utils/validators.js';
import { PERMISSIONS, RESOURCES } from '../utils/constants.js';
import crypto from 'crypto';

const router = express.Router();

/**
 * Generate unique, random patient ID
 * Format: PAT-XXXXXXXXXXXX (12 random alphanumeric characters)
 * No timestamp or sequential patterns to prevent prediction
 */
function generatePatientId() {
  const chars = 'ABCDEFGHJKLMNPQRSTUVWXYZ23456789'; // Exclude ambiguous chars (0,O,1,I)
  let id = 'PAT-';

  // Generate 12 random characters
  const randomBytes = crypto.randomBytes(12);
  for (let i = 0; i < 12; i++) {
    id += chars[randomBytes[i] % chars.length];
  }

  return id;
}

/**
 * GET /api/patients
 * Get all patients with pagination and search
 */
router.get(
  '/',
  authenticate,
  requirePermission(PERMISSIONS.VIEW_PATIENTS),
  asyncHandler(async (req, res) => {
    const {
      page = 1,
      limit = 10,
      search = '',
      sortBy = 'createdAt',
      sortOrder = 'desc',
    } = req.query;

    const skip = (parseInt(page) - 1) * parseInt(limit);

    // Build search query (will search in encrypted fields after decryption)
    const query = { isActive: true };

    // Note: Searching encrypted fields is complex. For production, consider:
    // 1. Searchable hash for common fields
    // 2. Encrypted search tokens
    // 3. Client-side filtering after decryption
    // For now, we'll search by patientId and blood type (unencrypted)

    if (search) {
      query.$or = [
        { patientId: { $regex: search, $options: 'i' } },
        { bloodType: { $regex: search, $options: 'i' } },
      ];
    }

    const [patients, total] = await Promise.all([
      Patient.find(query)
        .sort({ [sortBy]: sortOrder === 'desc' ? -1 : 1 })
        .skip(skip)
        .limit(parseInt(limit)),
      Patient.countDocuments(query),
    ]);

    res.json({
      success: true,
      data: {
        patients,
        pagination: {
          total,
          page: parseInt(page),
          limit: parseInt(limit),
          pages: Math.ceil(total / parseInt(limit)),
        },
      },
    });
  })
);

/**
 * GET /api/patients/:id
 * Get patient by ID
 */
router.get(
  '/:id',
  authenticate,
  requirePermission(PERMISSIONS.VIEW_PATIENTS),
  asyncHandler(async (req, res) => {
    const patient = await Patient.findById(req.params.id);

    if (!patient) {
      return res.status(404).json({
        success: false,
        error: {
          code: 'NOT_FOUND',
          message: 'Patient not found',
        },
      });
    }

    res.json({
      success: true,
      data: patient,
    });
  })
);

/**
 * POST /api/patients
 * Register new patient
 */
router.post(
  '/',
  authenticate,
  requirePermission(PERMISSIONS.CREATE_PATIENTS),
  validateSchema(createPatientSchema),
  auditCreate(RESOURCES.PATIENT),
  asyncHandler(async (req, res) => {
    const patientData = req.validated;

    // Generate unique patient ID
    patientData.patientId = generatePatientId();

    // Convert arrays to JSON strings for encryption
    if (patientData.allergies) {
      patientData.allergies = JSON.stringify(patientData.allergies);
    }
    if (patientData.chronicConditions) {
      patientData.chronicConditions = JSON.stringify(patientData.chronicConditions);
    }

    // Create patient (encryption happens in pre-save hook)
    const patient = await Patient.create(patientData);

    res.status(201).json({
      success: true,
      data: {
        id: patient._id,
        patientId: patient.patientId,
        message: 'Patient registered successfully',
      },
    });
  })
);

/**
 * PUT /api/patients/:id
 * Update patient
 */
router.put(
  '/:id',
  authenticate,
  requirePermission(PERMISSIONS.EDIT_PATIENTS),
  validateSchema(updatePatientSchema),
  auditUpdate(RESOURCES.PATIENT),
  asyncHandler(async (req, res) => {
    const updateData = req.validated;

    // Convert arrays to JSON strings for encryption
    if (updateData.allergies) {
      updateData.allergies = JSON.stringify(updateData.allergies);
    }
    if (updateData.chronicConditions) {
      updateData.chronicConditions = JSON.stringify(updateData.chronicConditions);
    }

    // Find the patient first
    const patient = await Patient.findById(req.params.id);

    if (!patient) {
      return res.status(404).json({
        success: false,
        error: {
          code: 'NOT_FOUND',
          message: 'Patient not found',
        },
      });
    }

    // Update fields - this will trigger pre-save hooks when we call save()
    Object.assign(patient, updateData);

    // Save the patient - this triggers pre-save hooks for encryption
    await patient.save();

    res.json({
      success: true,
      data: patient,
      message: 'Patient updated successfully',
    });
  })
);

/**
 * DELETE /api/patients/:id
 * Deactivate patient (soft delete)
 */
router.delete(
  '/:id',
  authenticate,
  requirePermission(PERMISSIONS.DELETE_PATIENTS),
  auditDelete(RESOURCES.PATIENT),
  asyncHandler(async (req, res) => {
    const patient = await Patient.findByIdAndUpdate(
      req.params.id,
      { isActive: false },
      { new: true }
    );

    if (!patient) {
      return res.status(404).json({
        success: false,
        error: {
          code: 'NOT_FOUND',
          message: 'Patient not found',
        },
      });
    }

    res.json({
      success: true,
      message: 'Patient deactivated successfully',
    });
  })
);

/**
 * GET /api/patients/search/:patientId
 * Search patient by patient ID
 */
router.get(
  '/search/:patientId',
  authenticate,
  requirePermission(PERMISSIONS.VIEW_PATIENTS),
  asyncHandler(async (req, res) => {
    const patient = await Patient.findOne({
      patientId: req.params.patientId,
      isActive: true,
    });

    if (!patient) {
      return res.status(404).json({
        success: false,
        error: {
          code: 'NOT_FOUND',
          message: 'Patient not found',
        },
      });
    }

    res.json({
      success: true,
      data: patient,
    });
  })
);

export default router;
