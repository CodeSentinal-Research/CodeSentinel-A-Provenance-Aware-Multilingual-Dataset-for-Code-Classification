/**
 * College-Specific Templates & Starter Data
 * Created by Arghyajit Saha for Students
 */

export const COLLEGE_TEMPLATES = [
  {
    id: 'assignment',
    name: 'College Assignment with Cover Page',
    category: 'Assignments',
    icon: 'GraduationCap',
    description: 'Formatted assignment with student roll no, professor name, course code, problem statements, and solutions.',
    content: `# DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING
### ACADEMIC YEAR 2026-2027 • SEMESTER VI

---

| Assignment Details | Information |
| :--- | :--- |
| **Course Title:** | Design & Analysis of Algorithms (CS302) |
| **Assignment No:** | Assignment #04: Dynamic Programming & Graphs |
| **Student Name:** | Rahul Sharma |
| **Roll Number:** | 2024-CS-0842 |
| **Submitted To:** | Prof. K. Mukherjee |
| **Submission Date:**| August 29, 2026 |

---

## 📌 Problem Statement 1: Matrix Chain Multiplication

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

### Mathematical Formulation
Let the dimensions of matrices $A_1, A_2, \\dots, A_n$ be given by an array $p = \\langle p_0, p_1, \\dots, p_n \\rangle$, where matrix $A_i$ has dimension $p_{i-1} \\times p_i$.

The recursive formulation for the minimum cost $m[i, j]$:

$$m[i, j] = \\begin{cases} 
0 & \\text{if } i = j \\\\
\\min_{i \\leq k < j} \\left\\{ m[i, k] + m[k+1, j] + p_{i-1}p_k p_j \\right\\} & \\text{if } i < j
\\end{cases}$$

### Algorithm Implementation (Python)

\`\`\`python
def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * (n + 1) for _ in range(n + 1)]
    s = [[0] * (n + 1) for _ in range(n + 1)]

    for length in range(2, n + 1):
        for i in range(1, n - length + 2):
            j = i + length - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return m, s
\`\`\`

---

<!-- pagebreak -->

## 📌 Problem Statement 2: Shortest Path Analysis

\`\`\`mermaid
graph LR
    S((Source S)) -->|4| A((Node A))
    S -->|2| B((Node B))
    A -->|5| C((Node C))
    B -->|1| A
    B -->|8| D((Node D))
    A -->|10| D
    C -->|2| D
    D -->|6| T(((Target T)))
\`\`\`

### Complexity Summary

| Algorithm | Time Complexity | Space Complexity | Supports Negative Edges? |
| :--- | :---: | :---: | :---: |
| **Dijkstra's Algorithm** | $\\mathcal{O}((V + E) \\log V)$ | $\\mathcal{O}(V)$ | ❌ No |
| **Bellman-Ford Algorithm** | $\\mathcal{O}(V \\cdot E)$ | $\\mathcal{O}(V)$ | ✅ Yes |
| **Floyd-Warshall (All-Pairs)** | $\\mathcal{O}(V^3)$ | $\\mathcal{O}(V^2)$ | ✅ Yes (No neg cycles) |

---

> [!TIP]
> **Conclusion:** For dense graphs without negative weight cycles, Dijkstra with Fibonacci heaps achieves near-optimal asymptotic throughput.

**Student Signature:** \`Rahul Sharma\`  
**Date of Submission:** \`29/08/2026\`
`
  },
  {
    id: 'lab_report',
    name: 'Engineering Lab Report',
    category: 'Lab Reports',
    icon: 'FlaskConical',
    description: 'Complete laboratory experiment structure: Aim, apparatus, theory, circuit diagram, observations table, and results.',
    content: `# EXPERIMENT NO: 07
## STUDY AND VERIFICATION OF OPERATIONAL AMPLIFIER AS INVERTING AMPLIFIER

**Student Name:** Rahul Sharma | **Roll No:** 2024-EC-0114 | **Branch:** Electronics & Comm.  
**Subject:** Analog Integrated Circuits Lab (EC391) | **Date:** 29/08/2026  

---

## 1. Aim of the Experiment
1. To design and verify the operation of an inverting amplifier using IC 741.
2. To calculate the theoretical and practical closed-loop voltage gain.

---

## 2. Apparatus Required

| S.No | Equipment / Component | Specification | Quantity |
| :---: | :--- | :---: | :---: |
| 1 | Op-Amp IC | $\\mu\\text{A}741$ | 1 |
| 2 | Resistors | $1\\text{ k}\\Omega, 10\\text{ k}\\Omega$ | 2 |
| 3 | Dual Power Supply | $\\pm 15\\text{V}$ | 1 |
| 4 | Digital Storage Oscilloscope | $50\\text{ MHz}$ | 1 |

---

## 3. Circuit & Theory

\`\`\`mermaid
flowchart LR
    Vin[Input Vin] --> R1[Resistor R1]
    R1 --> InvertingPin[Inverting Pin]
    InvertingPin --> OpAmp((Op-Amp 741))
    GND[Ground] --> NonInvertingPin[Non-Inverting Pin]
    NonInvertingPin --> OpAmp
    OpAmp --> Vout[Output Vout]
    InvertingPin --- Rf[Feedback Rf] --- Vout
\`\`\`

### Voltage Gain Formula
$$A_v = -\\frac{R_f}{R_1}, \\quad V_{out} = -\\left(\\frac{R_f}{R_1}\\right) V_{in}$$

---

## 4. Observation Table

| S.No | $V_{in} (\\text{V}_{p-p})$ | $V_{out} (\\text{V}_{p-p})$ | Theoretical Gain ($A_{v\\text{, th}}$) | Practical Gain ($A_{v\\text{, pr}}$) | % Error |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 0.2 V | 1.98 V | -10.0 | -9.90 | 1.0% |
| 2 | 0.4 V | 3.96 V | -10.0 | -9.90 | 1.0% |
| 3 | 0.6 V | 5.92 V | -10.0 | -9.86 | 1.4% |

---

## 5. Results & Discussion
1. The closed-loop gain for the inverting configuration was found to be approximately $-9.9$, matching the theoretical value.
2. Phase inversion of $180^\\circ$ was verified on the oscilloscope.
`
  },
  {
    id: 'lecture_notes',
    name: 'Class Lecture Notes',
    category: 'Study Notes',
    icon: 'BookOpen',
    description: 'Clean Cornell notes style: Date, subject, professor, topics, key formulas, diagrams, and summary.',
    content: `# LECTURE NOTES: DATABASE MANAGEMENT SYSTEMS (CS401)
**Date:** 29 August 2026 | **Professor:** Dr. S. Sengupta | **Lecture:** #14  
**Topics Covered:** B+ Trees, Indexing Strategies, Buffer Management  

---

## 🎯 Key Concepts & Definitions

- **Dense Index:** An index record appears for *every* search-key value in the file.
- **Sparse Index:** An index record appears for only *some* search-key values.
- **B+ Tree Invariant:** All leaf nodes are at the same depth.

---

## 📐 B+ Tree Order & Fanout Formula

Let disk block size be $B$, pointer size be $P$, and search-key size be $K$.  
The order $n$ satisfies:

$$n \\cdot P + (n - 1) \\cdot K \\leq B \\implies n \\leq \\frac{B + K}{P + K}$$

---

## 🌳 B+ Tree Visual Structure

\`\`\`mermaid
flowchart TD
    Root["[ 20 | 50 ]"] --> Child1["[ 10 | 15 ]"]
    Root --> Child2["[ 25 | 45 ]"]
    Child1 --> Leaf1["[ 5, 10 ]"]
    Child1 --> Leaf2["[ 15, 18 ]"]
    Child2 --> Leaf3["[ 20, 25 ]"]
    Child2 --> Leaf4["[ 30, 40 ]"]
    Leaf1 -.-> Leaf2 -.-> Leaf3 -.-> Leaf4
\`\`\`

---

## ⚡ Summary for Exam Revision
1. B+ Trees minimize random I/O operations because height is typically $\\leq 3$.
2. Leaves are linked sequentially, making range queries $\\mathcal{O}(k)$ after initial lookup.
`
  },
  {
    id: 'exam_cheatsheet',
    name: 'Exam Quick Revision Cheatsheet',
    category: 'Exam Prep',
    icon: 'Zap',
    description: 'High-density 2-column formula card for fast exam revision and problem solving.',
    content: `# COMPACT EXAM CHEAT SHEET: CALCULUS & LINEAR ALGEBRA

---

## 1. Essential Differentiation & Integration

| Function $f(x)$ | Derivative $f'(x)$ | Indefinite Integral $\\int f(x) dx$ |
| :--- | :--- | :--- |
| $x^n$ | $n x^{n-1}$ | $\\frac{x^{n+1}}{n+1} + C \\quad (n \\neq -1)$ |
| $\\frac{1}{x}$ | $-\\frac{1}{x^2}$ | $\\ln|x| + C$ |
| $e^{ax}$ | $a e^{ax}$ | $\\frac{1}{a}e^{ax} + C$ |
| $\\sin(ax)$ | $a\\cos(ax)$ | $-\\frac{1}{a}\\cos(ax) + C$ |
| $\\cos(ax)$ | $-a\\sin(ax)$ | $\\frac{1}{a}\\sin(ax) + C$ |

---

## 2. Linear Algebra: Eigenvalues & Cayley-Hamilton

### Characteristic Equation
$$\\det(A - \\lambda I) = 0 \\implies \\lambda^n - c_1 \\lambda^{n-1} + \\dots + (-1)^n \\det(A) = 0$$

- **Trace Rule:** $\\sum_{i=1}^n \\lambda_i = \\text{Tr}(A) = \\sum_{i=1}^n a_{ii}$
- **Determinant Rule:** $\\prod_{i=1}^n \\lambda_i = \\det(A)$
- **Cayley-Hamilton Theorem:** Every square matrix satisfies its own characteristic equation: $P(A) = \\mathbf{0}$.
`
  },
  {
    id: 'resume',
    name: 'Placement & Internship Resume (1-Page)',
    category: 'Career',
    icon: 'Briefcase',
    description: 'Perfect 1-page college placement CV engineered to fit on a single A4 sheet.',
    content: `# RAHUL SHARMA
**Computer Science & Engineering Student**  
📍 Kolkata, India | 📱 +91 98765 43210 | 📧 rahul.sharma@college.edu  
🌐 [github.com/rahulsharma](https://github.com) | 💼 [linkedin.com/in/rahulsharma](https://linkedin.com)  

---

## 🎓 EDUCATION

### **B.Tech in Computer Science & Engineering** | *GPA: 8.92 / 10.0*
*Institute of Engineering & Management, Kolkata* • *2022 – 2026*

### **Higher Secondary (Class XII CBSE)** | *Score: 94.6%*
*Delhi Public School, Ruby Park* • *2022*

---

## 🛠️ TECHNICAL SKILLS

- **Languages:** Java, Python, C++, JavaScript, TypeScript, SQL
- **Frameworks & Tools:** React, Node.js, Express, FastAPI, PostgreSQL, MongoDB, Git, Docker
- **Core Subjects:** Data Structures, Algorithms, DBMS, Operating Systems, Computer Networks

---

## 🚀 PROJECTS

### **MarkForge - Student Document Studio** | *React, Tailwind CSS, KaTeX*
- Built an open-source Markdown & LaTeX document studio used by **500+ peers**.
- Integrated real-time KaTeX math rendering and multi-page PDF export engine.

### **Campus Placement Portal** | *Node.js, PostgreSQL, Docker*
- Built a role-based job application tracker for campus placement cells managing 1200+ profiles.

---

## 🏆 ACHIEVEMENTS

- **LeetCode:** 400+ problems solved, Knight Badge (Max Rating: 1840).
- **Hackathon:** 2nd Place in *Smart Bengal Hackathon 2025*.
`
  },
  {
    id: 'research_paper',
    name: 'Academic Research Paper (IEEE)',
    category: 'Research',
    icon: 'BookMarked',
    description: 'IEEE formatted conference / journal research paper template with citations.',
    content: `# An Empirical Study of Attention Mechanisms in Edge AI Inference

**Rahul Sharma$^1$, Arghyajit Saha$^2$**  
*Department of Computer Science & Engineering*  
*National Institute of Technology*  
\`{rahul.sharma, arghyajit.saha}@nit.ac.in\`

---

## Abstract
*Deploying transformer-based language and vision models on edge hardware is constrained by memory and compute overhead. In this paper, we evaluate quantization and sparse attention primitives on embedded ARM processors, achieving a $3.2\\times$ latency reduction.*

**Keywords—** Edge AI, Transformers, Quantization, Self-Attention, Embedded Systems.

---

## I. Introduction
The standard scaled dot-product attention function is formalized as:

$$\\text{Attention}(Q, K, V) = \\text{softmax}\\left( \\frac{QK^T}{\\sqrt{d_k}} \\right) V$$

For an input sequence of length $N$ with hidden dimension $d$, computing $QK^T$ requires $\\mathcal{O}(N^2 d)$ operations and $\\mathcal{O}(N^2)$ memory footprint.

---

## II. Mathematical Formulation
Linearized attention replaces the softmax kernel to achieve $\\mathcal{O}(Nd^2)$ scaling:

$$\\text{LinearAttention}(Q, K, V) = \\frac{\\phi(Q) \\left( \\phi(K)^T V \\right)}{\\phi(Q) \\sum_{j=1}^N \\phi(K_j)^T}$$

---

## References
1. A. Vaswani et al., "Attention is all you need," in *NeurIPS*, 2017.
2. K. Choromanski et al., "Rethinking attention with performers," in *ICLR*, 2021.
`
  }
];
