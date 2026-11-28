import numpy as np
from scipy.spatial.distance import pdist, squareform
from collections import defaultdict
import pandas as pd
import os

def calculate_features_fun(Eval_Obj, sign_indices, cell_ids_in_patches, patchwise_tissue_masks, output_file_NEW): 

    # Initialize lists to store results
    patch_ids = []
    efficiency_scores_T = []
    efficiency_scores_L = []
    efficiency_scores_P = []
    efficiency_scores_M = []
    efficiency_scores_N = []
    efficiency_scores_E = []
    efficiency_scores_F = []
    cell_counts_T = []
    cell_counts_L = []
    cell_counts_P = []
    cell_counts_M = []
    cell_counts_N = []
    cell_counts_E = []
    cell_counts_F = []

    # Minimum cells required for meaningful packing analysis
    MIN_CELLS = 5

    def compute_packing_efficiency(centroids, min_cells=MIN_CELLS):
        if len(centroids) < min_cells:
            return np.nan
    
        # Calculate observed distances between centroids
        distances = pdist(centroids)
        if len(distances) == 0:
            return np.nan
    
        # Calculate mean observed distance between neighboring cells
        observed_mean_dist = np.mean(distances)
    
        # Calculate ideal packing distance based on hexagonal arrangement
        # In perfect hexagonal packing, distance between centers is constant
        area_per_cell = (np.max(centroids[:,0]) - np.min(centroids[:,0])) * \
                        (np.max(centroids[:,1]) - np.min(centroids[:,1])) / len(centroids)
        ideal_dist = np.sqrt(2 * area_per_cell / np.sqrt(3))  # hexagonal packing
    
        # Compute efficiency score (ratio of ideal to observed distance)
        # Clip to max of 1.0 as we can't be more efficient than ideal
        efficiency = min(ideal_dist / observed_mean_dist, 1.0) if observed_mean_dist > 0 else np.nan
    
        return efficiency

    # Process each patch
    for patch_id, cell_ids_in_patch, patch_tissue_mask in zip(sign_indices, cell_ids_in_patches, patchwise_tissue_masks):
        print(f'Processing patch {patch_id}')
    
        # Get cell objects for current patch
        cells_objects_in_patch = [Eval_Obj.single_cell_list[i] for i in cell_ids_in_patch]
    
        # Group cells by type
        cell_groups = defaultdict(list)
        for cell in cells_objects_in_patch:
            if cell.cell_class == 'Epithelial':
                cell_groups['T'].append(cell)
            elif cell.cell_class == 'Lymphocyte':
                cell_groups['L'].append(cell)
            elif cell.cell_class == 'Plasma':
                cell_groups['P'].append(cell)
            elif cell.cell_class == 'Macrophage':
                cell_groups['M'].append(cell)
            elif cell.cell_class == 'Neutrophil':
                cell_groups['N'].append(cell)
            elif cell.cell_class == 'Eosinophil':
                cell_groups['E'].append(cell)
            elif cell.cell_class == 'Connective':
                cell_groups['F'].append(cell)
    
        # Store patch ID
        patch_ids.append(patch_id)
    
        # Process each cell type
        for cell_type, cells in [('T', cell_groups['T']), ('L', cell_groups['L']), 
                                ('P', cell_groups['P']), ('M', cell_groups['M']),
                                ('N', cell_groups['N']), ('E', cell_groups['E']),
                                ('F', cell_groups['F'])]:
        
            # Get centroids for current cell type
            centroids = np.array([cell.CentroidPix for cell in cells])
        
            # Compute efficiency score
            if len(cells) >= MIN_CELLS:
                efficiency = compute_packing_efficiency(centroids)
            else:
                efficiency = np.nan
            
            # Store results
            if cell_type == 'T':
                efficiency_scores_T.append(efficiency)
                cell_counts_T.append(len(cells))
            elif cell_type == 'L':
                efficiency_scores_L.append(efficiency)
                cell_counts_L.append(len(cells))
            elif cell_type == 'P':
                efficiency_scores_P.append(efficiency)
                cell_counts_P.append(len(cells))
            elif cell_type == 'M':
                efficiency_scores_M.append(efficiency)
                cell_counts_M.append(len(cells))
            elif cell_type == 'N':
                efficiency_scores_N.append(efficiency)
                cell_counts_N.append(len(cells))
            elif cell_type == 'E':
                efficiency_scores_E.append(efficiency)
                cell_counts_E.append(len(cells))
            elif cell_type == 'F':
                efficiency_scores_F.append(efficiency)
                cell_counts_F.append(len(cells))

    # Create dataframe and save results
    df = pd.DataFrame({
        'PATCH_ID': patch_ids,
        'T_PACKING_EFFICIENCY': efficiency_scores_T,
        'L_PACKING_EFFICIENCY': efficiency_scores_L,
        'P_PACKING_EFFICIENCY': efficiency_scores_P,
        'M_PACKING_EFFICIENCY': efficiency_scores_M,
        'N_PACKING_EFFICIENCY': efficiency_scores_N,
        'E_PACKING_EFFICIENCY': efficiency_scores_E,
        'F_PACKING_EFFICIENCY': efficiency_scores_F,
        'T_CELL_COUNT': cell_counts_T,
        'L_CELL_COUNT': cell_counts_L,
        'P_CELL_COUNT': cell_counts_P,
        'M_CELL_COUNT': cell_counts_M,
        'N_CELL_COUNT': cell_counts_N,
        'E_CELL_COUNT': cell_counts_E,
        'F_CELL_COUNT': cell_counts_F
    })

    # Save results
    output_file = './coding_input_output/CODE_OUTPUT/idea_database_94074b_20250209_163224_REFINE/7cvsd6q7oukq.csv'
    df.to_csv(output_file_NEW, index=False) 

    '''
    Output metrics explanation:

    T_PACKING_EFFICIENCY: Circular packing efficiency score for tumor cells (0-1, higher = more efficient packing)
    L_PACKING_EFFICIENCY: Circular packing efficiency score for lymphocytes (0-1)
    P_PACKING_EFFICIENCY: Circular packing efficiency score for plasma cells (0-1)
    M_PACKING_EFFICIENCY: Circular packing efficiency score for macrophages (0-1)
    N_PACKING_EFFICIENCY: Circular packing efficiency score for neutrophils (0-1)
    E_PACKING_EFFICIENCY: Circular packing efficiency score for eosinophils (0-1)
    F_PACKING_EFFICIENCY: Circular packing efficiency score for fibroblasts (0-1)
    T_CELL_COUNT: Number of tumor cells in patch
    L_CELL_COUNT: Number of lymphocytes in patch
    P_CELL_COUNT: Number of plasma cells in patch
    M_CELL_COUNT: Number of macrophages in patch
    N_CELL_COUNT: Number of neutrophils in patch
    E_CELL_COUNT: Number of eosinophils in patch
    F_CELL_COUNT: Number of fibroblasts in patch

    Patch size mode explanation:
    Using standard_1000m patches as circular packing analysis focuses on local cell organization patterns.
    The 1000μm patch size provides sufficient area to analyze meaningful cell clusters while maintaining
    local context appropriate for cell-cell spatial relationships and packing arrangements.
    '''