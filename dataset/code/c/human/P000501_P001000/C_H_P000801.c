#ifndef QWENCUDA_H
#define QWENCUDA_H

#define CUDA_CHECK(call)                                                 \
do {                                                                     \
    cudaError_t err__ = (call);                                          \
    if (err__ != cudaSuccess) {                                          \
        fprintf(stderr, "CUDA error at %s:%d: %s\n", __FILE__, __LINE__, \
                cudaGetErrorString(err__));                              \
        exit(EXIT_FAILURE);                                              \
    }                                                                    \
} while (0)

enum DTYPE {
    DTYPE_INT,
    DTYPE_FLOAT
};

enum DEVICE {
    DEVICE_CPU,
    DEVICE_CUDA
};

enum SCALAR_OP_TYPE {
    OP_DIV,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_SQRT,
};

enum ELEM_OP_TYPE {
    ELEM_OP_ADD,
    ELEM_OP_MUL
};

typedef struct {
    enum DTYPE dtype;
    enum DEVICE device;
    union {
        void *as_void;
        int *as_int;
        float *as_float;
    } data;
    int *strides;
    int *dims;
    int ndims;
} matrix;

typedef struct {
    matrix *w_embeddings;
    matrix *w_lm_head;
    matrix *w_final_rmsnorm;
    matrix **w_pre_attention_rmsnorm;
    matrix **w_pre_ffn_rmsnorm;
    matrix **w_q;
    matrix **w_k;
    matrix **w_v;
    matrix **w_o;
    matrix **w_q_norm;
    matrix **w_k_norm;
    matrix **w_up;
    matrix **w_gate;
    matrix **w_down;
    unsigned int n_layers;
    unsigned int n_h_q;
    unsigned int n_h_k;
} qwen_weights;

typedef struct {
    matrix **k;
    matrix **v;
    unsigned int n_layers;
    unsigned int max_seq_len;
} qwen_kv_cache;


#ifdef __cplusplus
extern "C" {
#endif

void qwen_mat_create_empty(matrix **m, int dim0, int dim1, enum DTYPE dtype, char **err);
void qwen_mat_create(void *data, int n, int *dims, enum DTYPE dtype, matrix **m, char **err);
void qwen_mat_scalar_op_in(matrix *m_a, float s, enum SCALAR_OP_TYPE op);
void qwen_mat_elementwise_op_in(matrix *m_a, matrix *m_b, enum ELEM_OP_TYPE op);
void qwen_mat_sum(matrix *m_a, matrix *out, int dim);
void qwen_mat_max_rows(matrix *m_a, matrix *out);
void qwen_mat_mul_mat(matrix *m_a, matrix *m_b, matrix *out);
void qwen_mat_create_causal_mask(matrix **m_mask, int N, int M);
void qwen_mat_transpose(matrix *m);
void qwen_mat_l2_normalize_in(matrix *proj);
void qwen_mat_scale_row_vector_in(matrix *x, matrix *weight);
void qwen_mat_split(matrix *m, matrix *split_arr, int dim, int n_splits);
void qwen_mat_destroy(matrix *m);

void qwen_kv_cache_create(qwen_weights *w, int max_seq_len, qwen_kv_cache **cache, char **err);
void qwen_kv_cache_destroy(qwen_kv_cache *cache);

void qwen_dl_sigmoid(matrix *m_a);
void qwen_dl_swish(matrix *m_a);
void qwen_dl_softmax_forward(matrix *m_a, matrix *out, matrix *mask);
void qwen_dl_embedding_forward(matrix *m_a, matrix *embeddings, matrix *out);
void qwen_dl_rmsnorm_forward(matrix *m_a, matrix *gain, matrix *out, float eps);
void qwen_dl_ffn_forward(matrix *x, matrix *up, matrix *gate, matrix *down, matrix *out);
void qwen_dl_init_rope(float theta, int max_seq_length, int dim_size, matrix **rope_matrix);
void qwen_dl_scaled_dot_product_attention_forward(
        matrix *theta,
        matrix *q_proj, matrix *k_proj, matrix *v_proj,
        matrix *w_q_norm, matrix *w_k_norm,
        matrix *qk_out, matrix *qk_masked, matrix *qkv,
        matrix *k_cache, matrix *v_cache, int pos);
void qwen_dl_grouped_query_attention_forward(
        matrix *x, matrix *theta, matrix *w_q, matrix *w_k, matrix *w_v, matrix *w_o,
        matrix *w_q_norm, matrix *w_k_norm,
        matrix *qkv, matrix *out,
        unsigned int n_h_q, unsigned int n_h_k,
        qwen_kv_cache *cache, int layer_idx, int pos);
void qwen_dl_transformer_block_forward(
        matrix *x,
        matrix *theta,
        matrix *w_pre_attention_rmsnorm, matrix *w_pre_ffn_rmsnorm,
        matrix *w_q, matrix *w_k, matrix *w_v, matrix *w_o,
        matrix *w_q_norm, matrix *w_k_norm,
        matrix *attn_in, matrix *qkv, matrix *attn_out,
        matrix *ffn_in, matrix *up, matrix *gate, matrix *down, matrix *ffn_out,
        matrix *out,
        unsigned int n_h_q, unsigned int n_h_k,
        qwen_kv_cache *cache, int layer_idx, int pos);

void qwen_forward(matrix *x, matrix *theta, qwen_weights *weights, qwen_kv_cache *cache, int pos, int *out_token_id);
void qwen_decode(int *x, int n, qwen_weights *weights, int num_tokens, int* out_tokens);

void qwen_weights_destroy(qwen_weights *w);
void print_mat(matrix *m);

#ifdef __cplusplus
}
#endif

#endif