// ============================================
// CAMPUS QUEST ANALYZER - Main Script
// ============================================

// Achievement System
const achievements = {
    "first_search": { name: "First Quest", description: "Complete your first search", icon: "🎯", unlocked: false },
    "explorer_master": { name: "Campus Explorer", description: "Complete both DFS and BFS tours", icon: "🗺️", unlocked: false },
    "sorting_expert": { name: "Sorting Master", description: "Complete both sorting algorithms", icon: "🏆", unlocked: false },
    "perfect_score": { name: "Perfect Grade", description: "Sort a list perfectly", icon: "⭐", unlocked: false },
    "quick_solver": { name: "Quick Solver", description: "Complete a search in under 5 seconds", icon: "⚡", unlocked: false }
};

// Binary Search Tree for Enrollment
class Node {
    constructor(id) {
        this.id = id;
        this.left = null;
        this.right = null;
    }
}

class BST {
    constructor() {
        this.root = null;
        this.searchPath = [];
    }

    insert(id) {
        if (this.root === null) {
            this.root = new Node(id);
        } else {
            this._insertNode(this.root, id);
        }
    }

    _insertNode(node, id) {
        if (id < node.id) {
            if (node.left === null) {
                node.left = new Node(id);
            } else {
                this._insertNode(node.left, id);
            }
        } else {
            if (node.right === null) {
                node.right = new Node(id);
            } else {
                this._insertNode(node.right, id);
            }
        }
    }

    search(id) {
        this.searchPath = [];
        return this._searchNode(this.root, id);
    }

    _searchNode(node, id) {
        if (node === null) return false;
        this.searchPath.push(node.id);
        if (id === node.id) return true;
        if (id < node.id) return this._searchNode(node.left, id);
        return this._searchNode(node.right, id);
    }
}

const studentBST = new BST();
[50, 30, 70, 20, 40, 60, 80].forEach(id => studentBST.insert(id));

// ============================================
// NAVIGATION FUNCTIONS
// ============================================

function goHome() {
    hideAllContainers();
    document.getElementById('questHub').classList.add('active');
}

function hideAllContainers() {
    document.querySelectorAll('.container').forEach(container => {
        container.classList.remove('active');
    });
    document.getElementById('progressModal').classList.add('hidden');
}

function startEnrollmentGate() {
    hideAllContainers();
    document.getElementById('enrollmentGate').classList.add('active');
    clearEnrollmentDisplay();
}

function startCampusExplorer() {
    hideAllContainers();
    document.getElementById('campusExplorer').classList.add('active');
    initializeCampusGraph();
}

function startAcademicArena() {
    hideAllContainers();
    document.getElementById('academicArena').classList.add('active');
    initializeSortingVisualization();
}

function showProgress() {
    document.getElementById('progressModal').classList.remove('hidden');
    displayAchievements();
}

function closeModal() {
    document.getElementById('progressModal').classList.add('hidden');
}

// ============================================
// ENROLLMENT GATE - Binary Search Tree
// ============================================

function clearEnrollmentDisplay() {
    document.getElementById('enrollmentResult').classList.add('hidden');
    document.getElementById('studentId').value = '';
}

function searchStudentId() {
    const studentIdInput = document.getElementById('studentId').value.trim();
    const resultBox = document.getElementById('enrollmentResult');

    if (!studentIdInput) {
        alert('Please enter a Student ID');
        return;
    }

    const studentId = parseInt(studentIdInput);
    const startTime = performance.now();
    const found = studentBST.search(studentId);
    const endTime = performance.now();
    const searchTime = (endTime - startTime).toFixed(2);

    resultBox.classList.remove('hidden', 'success', 'error');

    if (found) {
        resultBox.classList.add('success');
        resultBox.innerHTML = `✅ Access Granted!<br><small>Found ID ${studentId} in ${searchTime}ms via path: ${studentBST.searchPath.join(' → ')}</small>`;
        unlockAchievement('first_search');
        
        if (searchTime < 5) {
            unlockAchievement('quick_solver');
        }
    } else {
        resultBox.classList.add('error');
        resultBox.innerHTML = `❌ Access Denied<br><small>Student ID ${studentId} not found in system</small>`;
    }

    visualizeBSTSearch();
}

function visualizeBSTSearch() {
    const container = document.getElementById('treeVisualization');
    
    function buildTreeHTML(node, depth = 0) {
        if (!node) return '';
        const isInPath = studentBST.searchPath.includes(node.id);
        const highlight = isInPath ? 'style="color: #10b981; font-weight: bold;"' : '';
        
        return `
            <div style="margin-left: ${depth * 40}px;">
                <span ${highlight}>● ${node.id}</span>
                ${node.left ? buildTreeHTML(node.left, depth + 1) : ''}
                ${node.right ? buildTreeHTML(node.right, depth + 1) : ''}
            </div>
        `;
    }

    container.innerHTML = `
        <div style="text-align: left; font-family: monospace; color: #6b7280;">
            <h4 style="color: #6366f1; margin-bottom: 1rem;">Binary Search Tree Structure</h4>
            ${buildTreeHTML(studentBST.root)}
            <p style="margin-top: 1rem; color: #999; font-size: 0.9rem;">🟢 Highlighted nodes show the search path</p>
        </div>
    `;
}

// ============================================
// CAMPUS EXPLORER - Graph Traversal
// ============================================

const campusBuildings = {
    0: { name: 'Main Gate', x: 150, y: 100, color: '#6366f1' },
    1: { name: 'Library', x: 350, y: 80, color: '#ec4899' },
    2: { name: 'Cafeteria', x: 550, y: 100, color: '#f59e0b' },
    3: { name: 'Gym', x: 300, y: 250, color: '#10b981' },
    4: { name: 'Science Hall', x: 550, y: 250, color: '#3b82f6' },
    5: { name: 'Admin Building', x: 400, y: 400, color: '#8b5cf6' },
};

const campusEdges = [
    [0, 1], [0, 3], [1, 2], [1, 3], [2, 4], [3, 5], [4, 5], [2, 5]
];

const campusGraph = {
    0: [1, 3],
    1: [0, 2, 3],
    2: [1, 4, 5],
    3: [0, 1, 5],
    4: [2, 5],
    5: [3, 4, 2]
};

function initializeCampusGraph() {
    drawCampusGraph([]);
}

function drawCampusGraph(visitedOrder = [], currentNode = -1) {
    const canvas = document.getElementById('campusGraph');
    const ctx = canvas.getContext('2d');
    
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.strokeStyle = '#e5e7eb';
    ctx.lineWidth = 2;
    campusEdges.forEach(([from, to]) => {
        const fromNode = campusBuildings[from];
        const toNode = campusBuildings[to];
        ctx.beginPath();
        ctx.moveTo(fromNode.x, fromNode.y);
        ctx.lineTo(toNode.x, toNode.y);
        ctx.stroke();
    });

    Object.entries(campusBuildings).forEach(([id, building]) => {
        const numId = parseInt(id);
        let nodeColor = building.color;
        let radius = 30;

        if (visitedOrder.includes(numId)) {
            nodeColor = '#10b981';
            radius = 35;
        }
        if (numId === currentNode) {
            nodeColor = '#ff6b6b';
            radius = 40;
        }

        ctx.fillStyle = nodeColor;
        ctx.beginPath();
        ctx.arc(building.x, building.y, radius, 0, 2 * Math.PI);
        ctx.fill();

        ctx.fillStyle = 'white';
        ctx.font = 'bold 16px Arial';
        ctx.textAlign = 'center';
        ctx.textBaseline = 'middle';
        ctx.fillText(numId, building.x, building.y - 5);

        ctx.fillStyle = '#1f2937';
        ctx.font = '12px Arial';
        ctx.fillText(building.name, building.x, building.y + 25);
    });
}

async function startDFSTraversal() {
    const visited = [];
    const logDiv = document.getElementById('tourLog');
    logDiv.innerHTML = '';

    await dfs(0, visited, logDiv);

    unlockAchievement('explorer_master');
    logDiv.innerHTML += '<p class="log-item" style="color: #10b981; font-weight: bold;">✅ DFS Tour Complete!</p>';
}

async function dfs(node, visited, logDiv) {
    visited.push(node);
    drawCampusGraph(visited, node);

    const building = campusBuildings[node];
    const logItem = document.createElement('p');
    logItem.className = 'log-item';
    logItem.textContent = `→ Visiting: ${building.name} (${node})`;
    logDiv.appendChild(logItem);

    await new Promise(resolve => setTimeout(resolve, 800));

    for (let neighbor of campusGraph[node]) {
        if (!visited.includes(neighbor)) {
            await dfs(neighbor, visited, logDiv);
        }
    }
}

async function startBFSTraversal() {
    const visited = [0];
    const queue = [0];
    const logDiv = document.getElementById('tourLog');
    logDiv.innerHTML = '';

    while (queue.length > 0) {
        const node = queue.shift();
        drawCampusGraph(visited, node);

        const building = campusBuildings[node];
        const logItem = document.createElement('p');
        logItem.className = 'log-item';
        logItem.textContent = `→ Visiting: ${building.name} (${node})`;
        logDiv.appendChild(logItem);

        await new Promise(resolve => setTimeout(resolve, 800));

        for (let neighbor of campusGraph[node]) {
            if (!visited.includes(neighbor)) {
                visited.push(neighbor);
                queue.push(neighbor);
            }
        }
    }

    unlockAchievement('explorer_master');
    logDiv.innerHTML += '<p class="log-item" style="color: #10b981; font-weight: bold;">✅ BFS Tour Complete!</p>';
}

function resetExplorer() {
    document.getElementById('tourLog').innerHTML = '<p class="placeholder">Choose a traversal method to begin...</p>';
    drawCampusGraph([]);
}

// ============================================
// ACADEMIC ARENA - Sorting Algorithms
// ============================================

let sortingState = {
    grades: [],
    names: [],
    isAnimating: false
};

function initializeSortingVisualization() {
    const gradeTxt = document.getElementById('gradeInput').value;
    const namesTxt = document.getElementById('gradeNames').value;
    
    sortingState.grades = gradeTxt.split(',').map(g => parseInt(g.trim())).filter(g => !isNaN(g) && g >= 0 && g <= 100);
    sortingState.names = namesTxt.split(',').map(n => n.trim()).slice(0, sortingState.grades.length);
    
    drawSortingBars();
}

function drawSortingBars(highlightIndices = []) {
    const canvas = document.getElementById('sortingCanvas');
    const ctx = canvas.getContext('2d');
    const padding = 40;
    const barWidth = (canvas.width - 2 * padding) / sortingState.grades.length;
    const maxGrade = 100;

    ctx.clearRect(0, 0, canvas.width, canvas.height);

    sortingState.grades.forEach((grade, idx) => {
        const barHeight = (grade / maxGrade) * (canvas.height - 2 * padding);
        const x = padding + idx * barWidth + barWidth / 4;
        const y = canvas.height - padding - barHeight;

        let color = '#6366f1';
        if (highlightIndices.includes(idx)) {
            color = '#ef4444';
        }

        ctx.fillStyle = color;
        ctx.fillRect(x, y, barWidth / 2, barHeight);

        ctx.fillStyle = '#1f2937';
        ctx.font = 'bold 12px Arial';
        ctx.textAlign = 'center';
        ctx.fillText(grade, x + barWidth / 4, y - 5);

        ctx.font = '10px Arial';
        ctx.fillStyle = '#6b7280';
        ctx.fillText(sortingState.names[idx] || `S${idx}`, x + barWidth / 4, canvas.height - padding + 15);
    });
}

async function startBubbleSort() {
    if (sortingState.isAnimating) return;
    sortingState.isAnimating = true;

    const grades = [...sortingState.grades];
    const names = [...sortingState.names];

    for (let i = 0; i < grades.length; i++) {
        for (let j = 0; j < grades.length - i - 1; j++) {
            drawSortingBars([j, j + 1]);
            await new Promise(resolve => setTimeout(resolve, 300));

            if (grades[j] > grades[j + 1]) {
                [grades[j], grades[j + 1]] = [grades[j + 1], grades[j]];
                [names[j], names[j + 1]] = [names[j + 1], names[j]];
            }
        }
    }

    sortingState.grades = grades;
    sortingState.names = names;
    drawSortingBars();

    displayLeaderboard();
    unlockAchievement('sorting_expert');
    unlockAchievement('perfect_score');

    sortingState.isAnimating = false;
}

async function startSelectionSort() {
    if (sortingState.isAnimating) return;
    sortingState.isAnimating = true;

    const grades = [...sortingState.grades];
    const names = [...sortingState.names];

    for (let i = 0; i < grades.length; i++) {
        let maxIdx = i;
        for (let j = i + 1; j < grades.length; j++) {
            drawSortingBars([i, maxIdx, j]);
            await new Promise(resolve => setTimeout(resolve, 300));

            if (grades[j] > grades[maxIdx]) {
                maxIdx = j;
            }
        }

        if (maxIdx !== i) {
            [grades[i], grades[maxIdx]] = [grades[maxIdx], grades[i]];
            [names[i], names[maxIdx]] = [names[maxIdx], names[i]];
        }
    }

    sortingState.grades = grades;
    sortingState.names = names;
    drawSortingBars();

    displayLeaderboard();
    unlockAchievement('sorting_expert');
    unlockAchievement('perfect_score');

    sortingState.isAnimating = false;
}

function displayLeaderboard() {
    const leaderboard = document.getElementById('leaderboard');
    leaderboard.innerHTML = '';

    sortingState.grades.forEach((grade, idx) => {
        const entry = document.createElement('div');
        entry.className = `leaderboard-entry rank-${idx + 1}`;
        entry.innerHTML = `
            <div class="leaderboard-rank">${idx + 1}</div>
            <div class="leaderboard-info">
                <div class="leaderboard-name">${sortingState.names[idx]}</div>
                <div class="leaderboard-grade">Grade: ${grade}/100</div>
            </div>
            <div class="grade-badge">${grade}%</div>
        `;
        leaderboard.appendChild(entry);
    });
}

function resetArena() {
    sortingState.grades = [];
    sortingState.names = [];
    sortingState.isAnimating = false;
    initializeSortingVisualization();
    document.getElementById('leaderboard').innerHTML = '<p class="placeholder">Sort to reveal the rankings...</p>';
}

// ============================================
// ACHIEVEMENT SYSTEM
// ============================================

function unlockAchievement(achievementKey) {
    if (!achievements[achievementKey].unlocked) {
        achievements[achievementKey].unlocked = true;
        showAchievementNotification(achievements[achievementKey].name);
    }
}

function showAchievementNotification(name) {
    const notification = document.createElement('div');
    notification.style.cssText = `
        position: fixed;
        top: 80px;
        right: 20px;
        background: linear-gradient(135deg, #ffd700, #ffed4e);
        color: #1f2937;
        padding: 1rem 1.5rem;
        border-radius: 8px;
        box-shadow: 0 10px 25px rgba(0, 0, 0, 0.3);
        font-weight: 600;
        z-index: 3000;
        animation: slideInRight 0.4s ease-out;
    `;
    notification.textContent = `🏆 Achievement Unlocked: ${name}`;
    document.body.appendChild(notification);

    setTimeout(() => {
        notification.style.animation = 'slideOutRight 0.4s ease-out';
        setTimeout(() => notification.remove(), 400);
    }, 3000);
}

function displayAchievements() {
    const list = document.getElementById('achievementsList');
    list.innerHTML = '';

    Object.entries(achievements).forEach(([key, ach]) => {
        const item = document.createElement('div');
        item.className = `achievement-item ${ach.unlocked ? 'unlocked' : 'locked'}`;
        item.innerHTML = `
            <div class="achievement-icon">${ach.icon}</div>
            <div class="achievement-info">
                <h4>${ach.name}</h4>
                <p>${ach.description}</p>
            </div>
        `;
        list.appendChild(item);
    });
}

function showAchievements() {
    showProgress();
}

// Initialize on load
window.addEventListener('load', () => {
    goHome();
});