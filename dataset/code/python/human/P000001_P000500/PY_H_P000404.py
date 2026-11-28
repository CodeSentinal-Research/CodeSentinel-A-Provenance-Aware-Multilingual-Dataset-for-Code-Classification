"""
Mock Doctor Database and Appointment Scheduling
"""

from datetime import datetime, timedelta
from typing import List, Dict
import json

class DoctorDatabase:
    def __init__(self):
        """Initialize doctor database with mock data"""
        self.doctors = self._load_mock_doctors()
        self.appointments = []
    
    def _load_mock_doctors(self) -> List[Dict]:
        """Load mock doctor data"""
        return [
            {
                "id": "doc_001",
                "name": "Dr. Sarah Johnson",
                "specialization": "General Medicine",
                "experience_years": 8,
                "rating": 4.8,
                "bio": "Experienced general practitioner specializing in chronic disease management",
                "availability": {
                    "Monday": ["09:00", "10:00", "11:00", "14:00", "15:00"],
                    "Tuesday": ["10:00", "11:00", "14:00", "15:00", "16:00"],
                    "Wednesday": ["09:00", "10:00", "14:00", "15:00"],
                    "Thursday": ["09:00", "11:00", "14:00", "16:00"],
                    "Friday": ["10:00", "11:00", "15:00", "16:00"]
                },
                "consultation_fee": "Free (AI Assisted)",
                "qualifications": ["MBBS", "MD"],
                "languages": ["English", "Spanish"]
            },
            {
                "id": "doc_002",
                "name": "Dr. Rajesh Patel",
                "specialization": "Cardiology",
                "experience_years": 12,
                "rating": 4.9,
                "bio": "Expert cardiologist with focus on preventive heart health",
                "availability": {
                    "Monday": ["09:00", "10:00", "14:00", "15:00"],
                    "Tuesday": ["10:00", "11:00", "15:00", "16:00"],
                    "Thursday": ["09:00", "11:00", "14:00"],
                    "Friday": ["10:00", "14:00", "15:00", "16:00"]
                },
                "consultation_fee": "Free (AI Assisted)",
                "qualifications": ["MBBS", "MD", "DM Cardiology"],
                "languages": ["English", "Hindi"]
            },
            {
                "id": "doc_003",
                "name": "Dr. Emily Chen",
                "specialization": "Neurology",
                "experience_years": 10,
                "rating": 4.7,
                "bio": "Specialist in neurological disorders and headache management",
                "availability": {
                    "Monday": ["09:00", "11:00", "14:00", "15:00"],
                    "Wednesday": ["10:00", "11:00", "14:00", "16:00"],
                    "Thursday": ["09:00", "10:00", "15:00"],
                    "Friday": ["09:00", "14:00", "15:00", "16:00"]
                },
                "consultation_fee": "Free (AI Assisted)",
                "qualifications": ["MBBS", "MD", "DM Neurology"],
                "languages": ["English", "Mandarin"]
            },
            {
                "id": "doc_004",
                "name": "Dr. Michael O'Brien",
                "specialization": "Diabetes Management",
                "experience_years": 15,
                "rating": 4.9,
                "bio": "Endocrinologist with expertise in diabetes and metabolic disorders",
                "availability": {
                    "Tuesday": ["09:00", "10:00", "14:00", "15:00", "16:00"],
                    "Wednesday": ["09:00", "11:00", "14:00"],
                    "Thursday": ["10:00", "11:00", "14:00", "15:00"],
                    "Friday": ["09:00", "10:00", "11:00", "14:00"]
                },
                "consultation_fee": "Free (AI Assisted)",
                "qualifications": ["MBBS", "MD", "DM Endocrinology"],
                "languages": ["English"]
            }
        ]
    
    def get_all_doctors(self) -> List[Dict]:
        """Get all doctors"""
        return [{
            "id": doc["id"],
            "name": doc["name"],
            "specialization": doc["specialization"],
            "experience_years": doc["experience_years"],
            "rating": doc["rating"]
        } for doc in self.doctors]
    
    def get_doctor_details(self, doctor_id: str) -> Dict:
        """Get full doctor details"""
        for doc in self.doctors:
            if doc["id"] == doctor_id:
                return doc
        return None
    
    def get_available_slots(self, doctor_id: str, days_ahead: int = 7) -> Dict:
        """Get available appointment slots for next N days"""
        doctor = self.get_doctor_details(doctor_id)
        if not doctor:
            return {}
        
        available_slots = {}
        current_date = datetime.now()
        
        for i in range(days_ahead):
            date = current_date + timedelta(days=i)
            day_name = date.strftime("%A")
            
            if day_name in doctor["availability"]:
                available_slots[date.strftime("%Y-%m-%d")] = {
                    "day": day_name,
                    "slots": doctor["availability"][day_name]
                }
        
        return available_slots
    
    def book_appointment(self, 
                        doctor_id: str,
                        patient_name: str,
                        appointment_date: str,
                        appointment_time: str) -> Dict:
        """Book an appointment"""
        doctor = self.get_doctor_details(doctor_id)
        if not doctor:
            return {"success": False, "message": "Doctor not found"}
        
        appointment = {
            "id": f"apt_{len(self.appointments) + 1}",
            "doctor_id": doctor_id,
            "doctor_name": doctor["name"],
            "patient_name": patient_name,
            "date": appointment_date,
            "time": appointment_time,
            "status": "confirmed",
            "booked_at": datetime.now().isoformat()
        }
        
        self.appointments.append(appointment)
        
        return {
            "success": True,
            "message": "Appointment booked successfully",
            "appointment": appointment
        }
    
    def search_doctors(self, specialization: str) -> List[Dict]:
        """Search doctors by specialization"""
        results = []
        specialization_lower = specialization.lower()
        
        for doc in self.doctors:
            if specialization_lower in doc["specialization"].lower():
                results.append({
                    "id": doc["id"],
                    "name": doc["name"],
                    "specialization": doc["specialization"],
                    "rating": doc["rating"],
                    "experience_years": doc["experience_years"]
                })
        
        return results
