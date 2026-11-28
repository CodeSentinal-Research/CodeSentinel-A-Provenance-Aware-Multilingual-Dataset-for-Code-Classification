import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from typing import List, Dict, Any, Tuple, TypeVar, Type
import random
import networkx as nx
from collections import defaultdict
from enum import Enum, auto
from dataclasses import dataclass, field
from typing import ClassVar

# Type variable for generic problem type
T = TypeVar('T', bound='BaseProblem')

class ProblemType(Enum):
    THREE_SAT = auto()
    GRAPH_COLORING = auto()
    SUBSET_SUM = auto()

@dataclass
class FieldParameters:
    DIFFUSION_COEFFICIENT: ClassVar[str] = 'diffusion_coefficient'
    ENCODING_STRENGTH: ClassVar[str] = 'encoding_strength'
    TIME_STEP: ClassVar[str] = 'time_step'
    MAX_ITERATIONS: ClassVar[str] = 'max_iterations'

class ProblemKeys:
    FIELD_ENCODING: str = 'field_encoding'
    SOLUTION: str = 'solution'
    CONVERGENCE_STEPS: str = 'convergence_steps'
    IS_VALID: str = 'is_valid'
    PROBLEM_TYPE: str = 'problem_type'

class ThreeSatKeys(ProblemKeys):
    CLAUSES: str = 'clauses'
    NUM_VARIABLES: str = 'num_variables'
    NUM_CLAUSES: str = 'num_clauses'
    IS_SATISFIABLE: str = 'is_satisfiable'

class GraphColoringKeys(ProblemKeys):
    EDGES: str = 'edges'
    NUM_VERTICES: str = 'num_vertices'
    COLORING: str = 'coloring'

class SubsetSumKeys(ProblemKeys):
    NUMBER_SET: str = 'number_set'
    TARGET: str = 'target'
    SUBSET_SELECTION: str = 'subset_selection'

@dataclass
class BaseProblem:
    field_encoding: np.ndarray
    solution: Any
    convergence_steps: int
    problem_type: ProblemType
    
    @classmethod
    def from_dict(cls: Type[T], data: Dict[str, Any]) -> T:
        return cls(**{k: v for k, v in data.items() if k in cls.__annotations__})
    
    def to_dict(self) -> Dict[str, Any]:
        return {k: getattr(self, k) for k in self.__annotations__}

@dataclass
class ThreeSatProblem(BaseProblem):
    clauses: List[List[int]]
    num_variables: int
    num_clauses: int
    is_satisfiable: bool
    problem_type: ProblemType = field(default=ProblemType.THREE_SAT, init=False)

@dataclass
class GraphColoringProblem(BaseProblem):
    edges: List[Tuple[int, int]]
    num_vertices: int
    coloring: List[int]
    is_valid: bool
    problem_type: ProblemType = field(default=ProblemType.GRAPH_COLORING, init=False)

@dataclass
class SubsetSumProblem(BaseProblem):
    number_set: List[int]
    target: int
    subset_selection: List[int]
    is_valid: bool
    problem_type: ProblemType = field(default=ProblemType.SUBSET_SUM, init=False)

class UnifiedMathDataset:
    def __init__(self, random_seed: int = 42):
        self.random_seed = random_seed
        np.random.seed(random_seed)
        torch.manual_seed(random_seed)
        random.seed(random_seed)
        
        # Field simulation parameters using class constants
        self.field_params = {
            FieldParameters.DIFFUSION_COEFFICIENT: 1.0,
            FieldParameters.ENCODING_STRENGTH: 2.0,
            FieldParameters.TIME_STEP: 0.01,
            FieldParameters.MAX_ITERATIONS: 100
        }
        
    def generate_3sat_dataset(self, n_problems: int = 10000, min_vars: int = 3, max_vars: int = 10) -> List[ThreeSatProblem]:
        problems = []
        for _ in range(n_problems):
            num_vars = np.random.randint(min_vars, max_vars + 1)
            num_clauses = min(3 * num_vars, 50)  # Reasonable number of clauses
            
            # Generate random 3-SAT problem
            clauses = []
            for _ in range(num_clauses):
                clause = np.random.choice(num_vars, 3, replace=False) + 1  # 1-based variables
                clause = [int(c * random.choice([-1, 1])) for c in clause]  # Randomly negate
                clauses.append(clause)
            
            # Encode problem in field
            field_encoding = self._encode_3sat_problem(clauses, num_vars)
            
            # Simple satisfiability check (placeholder for actual SAT solver)
            is_satisfiable = random.random() > 0.1  # 90% satisfiable
            solution = np.random.randint(0, 2, num_vars) if is_satisfiable else None
            
            problem = ThreeSatProblem(
                field_encoding=field_encoding,
                solution=solution,
                convergence_steps=np.random.randint(50, 200),
                clauses=clauses,
                num_variables=num_vars,
                num_clauses=num_clauses,
                is_satisfiable=is_satisfiable
            )
            problems.append(problem)
            
        return problems
    
    def generate_graph_coloring_dataset(self, n_problems: int = 5000, min_vertices: int = 3, max_vertices: int = 8) -> List[GraphColoringProblem]:
        problems = []
        for _ in range(n_problems):
            num_vertices = np.random.randint(min_vertices, max_vertices + 1)
            
            # Generate random graph
            p = 0.3  # Edge probability
            G = nx.erdos_renyi_graph(num_vertices, p)
            edges = list(G.edges())
            
            # Simple coloring (3-coloring)
            colors = [random.randint(0, 2) for _ in range(num_vertices)]
            is_valid = all(colors[u] != colors[v] for u, v in edges)
            
            # Encode problem in field
            field_encoding = self._encode_graph_coloring(G, 3)  # 3-coloring
            
            problem = GraphColoringProblem(
                field_encoding=field_encoding,
                solution=colors,
                convergence_steps=np.random.randint(30, 150),
                edges=edges,
                num_vertices=num_vertices,
                coloring=colors,
                is_valid=is_valid
            )
            problems.append(problem)
            
        return problems
    
    def generate_subset_sum_dataset(self, n_problems: int = 5000, min_set_size: int = 3, max_set_size: int = 10) -> List[SubsetSumProblem]:
        problems = []
        for _ in range(n_problems):
            set_size = np.random.randint(min_set_size, max_set_size + 1)
            
            # Generate random numbers and target sum
            numbers = np.random.randint(1, 100, set_size).tolist()
            target = np.random.randint(1, sum(numbers))
            
            # Simple subset check (placeholder for actual solver)
            has_solution = random.random() > 0.1  # 90% have solutions
            subset = random.sample(numbers, min(3, len(numbers))) if has_solution else []
            
            # Encode problem in field
            field_encoding = self._encode_subset_sum(numbers, target)
            
            problem = SubsetSumProblem(
                field_encoding=field_encoding,
                solution=subset,
                convergence_steps=np.random.randint(20, 100),
                number_set=numbers,
                target=target,
                subset_selection=subset,
                is_valid=has_solution
            )
            problems.append(problem)
            
        return problems
    
    def _encode_3sat_problem(self, clauses: List[List[int]], num_vars: int) -> np.ndarray:
        # Simple one-hot encoding of 3-SAT problem
        encoding = np.zeros((num_vars, 2))  # For each variable: [positive, negative] occurrences
        
        for clause in clauses:
            for lit in clause:
                var = abs(lit) - 1
                if var < num_vars:  # Safety check
                    if lit > 0:
                        encoding[var, 0] += 1
                    else:
                        encoding[var, 1] += 1
        
        # Normalize
        if np.max(encoding) > 0:
            encoding = encoding / np.max(encoding)
            
        return encoding.astype(np.float32)
    
    def _encode_graph_coloring(self, graph: nx.Graph, num_colors: int) -> np.ndarray:
        # Simple encoding of graph coloring problem
        num_vertices = len(graph.nodes())
        encoding = np.zeros((num_vertices, num_vertices + num_colors))
        
        # Adjacency matrix
        adj = nx.adjacency_matrix(graph).toarray()
        encoding[:, :num_vertices] = adj
        
        # One-hot encoding of color constraints
        for i in range(num_vertices):
            color = random.randint(0, num_colors - 1)
            encoding[i, num_vertices + color] = 1.0
            
        return encoding.astype(np.float32).reshape(1, -1)  # 1D to 2D
    
    def _encode_subset_sum(self, numbers: List[int], target: int) -> np.ndarray:
        max_num = max(numbers) if numbers else 1
        encoding = np.array(numbers) / max_num  # Normalize
        return encoding.reshape(1, -1)  # 1D to 2D


class UnifiedMathModel(nn.Module):
    def __init__(self, input_dim: int, hidden_dim: int = 128, num_layers: int = 3):
        super().__init__()
        
        # Shared encoder
        encoder_layers = []
        current_dim = input_dim
        for _ in range(num_layers):
            encoder_layers.extend([
                nn.Linear(current_dim, hidden_dim),
                nn.ReLU(),
                nn.LayerNorm(hidden_dim)
            ])
            current_dim = hidden_dim
            
        self.encoder = nn.Sequential(*encoder_layers)
        
        # Solution head (binary classification for each variable/position)
        self.solution_head = nn.Sequential(
            nn.Linear(hidden_dim, hidden_dim // 2),
            nn.ReLU(),
            nn.Linear(hidden_dim // 2, 1),
            nn.Sigmoid()
        )
        
        # Convergence head (regression for number of steps to converge)
        self.convergence_head = nn.Sequential(
            nn.Linear(hidden_dim, hidden_dim // 2),
            nn.ReLU(),
            nn.Linear(hidden_dim // 2, 1)
        )
    
    def forward(self, x: torch.Tensor, problem_type: ProblemType, sequence_length: int = 1) -> Tuple[torch.Tensor, torch.Tensor]:
        # x shape: [batch, seq_len, input_dim] or [batch, input_dim]
        if len(x.shape) == 2:
            x = x.unsqueeze(1)  # Add sequence dimension if missing
            
        batch_size, seq_len, _ = x.shape
        
        # Process through encoder
        x = x.view(-1, x.size(-1))  # Flatten batch and sequence
        encoded = self.encoder(x)
        
        # Reshape back to [batch, seq_len, hidden_dim]
        encoded = encoded.view(batch_size, seq_len, -1)
        
        # Get solution predictions
        solution_preds = self.solution_head(encoded).squeeze(-1)  # [batch, seq_len]
        
        # Get convergence predictions (use mean pooling over sequence)
        pooled = encoded.mean(dim=1)  # [batch, hidden_dim]
        convergence_preds = self.convergence_head(pooled)  # [batch, 1]
        
        return solution_preds, convergence_preds


class UnifiedMathTrainer:
    def __init__(
        self, 
        model: nn.Module,
        device: torch.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    ) -> None:
        self.model = model.to(device)
        self.device = device
        
        # Loss functions
        self.solution_criterion = nn.BCELoss()
        self.convergence_criterion = nn.MSELoss()
        
        # Optimizer and scheduler
        self.optimizer = torch.optim.AdamW(self.model.parameters(), lr=1e-4)
        self.scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(
            self.optimizer, mode='min', factor=0.5, patience=5, verbose=True
        )
    
    def train_epoch(self, train_loader: torch.utils.data.DataLoader) -> float:
        self.model.train()
        total_loss = 0.0
        
        for batch in train_loader:
            # Convert batch to problem instances
            if isinstance(batch, dict):
                # Handle case where batch is already a dictionary
                problem = ThreeSatProblem.from_dict(batch)
            else:
                # Handle case where batch is a list of problem instances
                problem = batch[0]  # Assuming batch size is 1 for simplicity
            
            # Prepare inputs and targets
            inputs = torch.tensor(problem.field_encoding, dtype=torch.float32).unsqueeze(0).to(self.device)
            solution_targets = torch.tensor(problem.solution, dtype=torch.float32).unsqueeze(0).to(self.device)
            convergence_targets = torch.tensor(problem.convergence_steps, dtype=torch.float32).unsqueeze(0).to(self.device)
            
            # Zero gradients
            self.optimizer.zero_grad()
            
            # Forward pass
            solution_preds, convergence_preds = self.model(
                inputs,
                problem_type=problem.problem_type,
                sequence_length=1
            )
            
            # Calculate losses
            solution_loss = self.solution_criterion(solution_preds, solution_targets)
            convergence_loss = self.convergence_criterion(
                convergence_preds.squeeze(), convergence_targets
            )
            
            # Combined loss
            loss = solution_loss + 0.1 * convergence_loss
            
            # Backward pass and optimize
            loss.backward()
            torch.nn.utils.clip_grad_norm_(self.model.parameters(), 1.0)
            self.optimizer.step()
            
            total_loss += loss.item()
        
        return total_loss / len(train_loader)
    
    def validate(self, val_loader: torch.utils.data.DataLoader) -> float:
        self.model.eval()
        val_loss = 0.0
        
        with torch.no_grad():
            for batch in val_loader:
                # Convert batch to problem instances
                if isinstance(batch, dict):
                    problem = ThreeSatProblem.from_dict(batch)
                else:
                    problem = batch[0]
                
                inputs = torch.tensor(problem.field_encoding, dtype=torch.float32).unsqueeze(0).to(self.device)
                solution_targets = torch.tensor(problem.solution, dtype=torch.float32).unsqueeze(0).to(self.device)
                convergence_targets = torch.tensor(problem.convergence_steps, dtype=torch.float32).unsqueeze(0).to(self.device)
                
                solution_preds, convergence_preds = self.model(
                    inputs,
                    problem_type=problem.problem_type,
                    sequence_length=1
                )
                
                solution_loss = self.solution_criterion(solution_preds, solution_targets)
                convergence_loss = self.convergence_criterion(
                    convergence_preds.squeeze(), convergence_targets
                )
                
                loss = solution_loss + 0.1 * convergence_loss
                val_loss += loss.item()
        
        return val_loss / len(val_loader)
    
    def train(
        self, 
        train_loader: torch.utils.data.DataLoader, 
        val_loader: torch.utils.data.DataLoader, 
        epochs: int = 100, 
        patience: int = 10,
        min_delta: float = 1e-4
    ) -> Dict[str, List[float]]:
        best_val_loss = float('inf')
        patience_counter = 0
        history = {
            'train_loss': [],
            'val_loss': [],
            'lr': []
        }
        
        for epoch in range(epochs):
            # Training phase
            train_loss = self.train_epoch(train_loader)
            
            # Validation phase
            val_loss = self.validate(val_loader)
            
            # Update learning rate
            self.scheduler.step(val_loss)
            current_lr = self.optimizer.param_groups[0]['lr']
            
            # Update history
            history['train_loss'].append(train_loss)
            history['val_loss'].append(val_loss)
            history['lr'].append(current_lr)
            
            # Print progress
            print(f'Epoch {epoch+1}/{epochs} - ' \
                  f'Train Loss: {train_loss:.4f} - ' \
                  f'Val Loss: {val_loss:.4f} - ' \
                  f'LR: {current_lr:.2e}')
            
            # Early stopping check
            if val_loss < best_val_loss - min_delta:
                best_val_loss = val_loss
                patience_counter = 0
                # Save best model
                torch.save(self.model.state_dict(), 'best_model.pt')
            else:
                patience_counter += 1
                if patience_counter >= patience:
                    print(f'Early stopping after {epoch+1} epochs')
                    break
        
        # Load best model
        self.model.load_state_dict(torch.load('best_model.pt'))
        return history