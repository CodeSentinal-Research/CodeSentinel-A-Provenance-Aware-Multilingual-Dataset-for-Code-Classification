from urllib import response
from rest_framework import viewsets, filters
from .models import Employee, Department, Role
from .serializers import EmployeeSerializer, DepartmentSerializer, RoleSerializer
from django_filters.rest_framework import DjangoFilterBackend

class EmployeeViewSet(viewsets.ModelViewSet):
    queryset = Employee.objects.select_related('department', 'role').all()
    serializer_class = EmployeeSerializer
    filter_backends = [DjangoFilterBackend, filters.SearchFilter, filters.OrderingFilter]
    filterset_fields = ['department', 'role', 'is_active']
    search_fields = ['first_name', 'last_name', 'employee_id', 'email']
    ordering_fields = ['date_joined', 'employee_id']

class DepartmentViewSet(viewsets.ModelViewSet):
    queryset = Department.objects.all()
    serializer_class = DepartmentSerializer

class RoleViewSet(viewsets.ModelViewSet):
    queryset = Role.objects.all()
    serializer_class = RoleSerializer


from core.elastic import es
from rest_framework.decorators import action

class EmployeeViewSet(viewsets.ModelViewSet):

    @action(detail=False, methods=['get'])
    def search(self, request):
        q = request.query_params.get("q", "")
        res = es.search(
            index="employees",
            query={"multi_match": {"query": q, "fields": ["name", "email", "department"]}}
        )
        return response(res['hits']['hits'])