from odoo import models, fields, api
from odoo.exceptions import ValidationError

class HrEmployee(models.Model):
    _inherit = 'hr.employee'

    @api.model
    def search_by_employee_id(self, emp_id):
        """Search employee by employee ID and return formatted data"""
        employee = self.search([('emp_id', '=', emp_id)], limit=1)
        if not employee:
            return False
            
        return {
            'id': employee.id,
            'name': employee.name,
            'work_email': employee.work_email or '',
            'work_phone': employee.mobile_phone or '',
            'department_id': [employee.section_id.id, employee.section_id.name] if employee.section_id else [False, ''],
            'company_id': [employee.default_unit_operating_id.id, employee.default_unit_operating_id.name] if employee.default_unit_operating_id else [False, ''],
            'image_1920': employee.image_1920 or False,
            'emp_id': employee.emp_id,
        }
