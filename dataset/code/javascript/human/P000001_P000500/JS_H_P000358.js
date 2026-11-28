import { Chess } from "https://cdn.jsdelivr.net/npm/chess.js@1.4.0/dist/esm/chess.js";

const boardEl = document.getElementById("board");
const startScreen = document.getElementById("startScreen");
const gameScreen = document.getElementById("gameScreen");
const statusText = document.getElementById("statusText");
const hintText = document.getElementById("hintText");
const startDifficulty = document.getElementById("startDifficulty");
const settingsDialog = document.getElementById("settingsDialog");
const colorThemeSelect = document.getElementById("colorTheme");
const nightModeToggle = document.getElementById("nightMode");
const newGameDialog = document.getElementById("newGameDialog");
const newGameDifficulty = document.getElementById("newGameDifficulty");
const startGameBtn = document.getElementById("startGameBtn");
const settingsBtn = document.getElementById("settingsBtn");
const openSettingsBtn = document.getElementById("openSettingsBtn");
const closeSettingsBtn = document.getElementById("closeSettingsBtn");
const closeNewGameBtn = document.getElementById("closeNewGameBtn");
const confirmNewGameBtn = document.getElementById("confirmNewGameBtn");
const newGameBtn = document.getElementById("newGameBtn");

const chess = new Chess();
let selectedSquare = null;
let legalTargets = [];
let aiThinking = false;
let searchDeadline = 0;
let currentDifficulty = Number(startDifficulty.value);
let lastMoveSquares = [];
let currentTheme = "brown";

const TIME_LIMIT_BY_DEPTH = {
  1: 100,
  2: 260,
  3: 520
};

const pieces = {
  wp: "♙",
  wn: "♘",
  wb: "♗",
  wr: "♖",
  wq: "♕",
  wk: "♔",
  bp: "♟",
  bn: "♞",
  bb: "♝",
  br: "♜",
  bq: "♛",
  bk: "♚"
};

const pieceValue = {
  p: 100,
  n: 320,
  b: 330,
  r: 500,
  q: 900,
  k: 0
};

const pst = {
  p: [
    [0, 0, 0, 0, 0, 0, 0, 0],
    [50, 50, 50, 50, 50, 50, 50, 50],
    [10, 10, 20, 30, 30, 20, 10, 10],
    [5, 5, 10, 25, 25, 10, 5, 5],
    [0, 0, 0, 20, 20, 0, 0, 0],
    [5, -5, -10, 0, 0, -10, -5, 5],
    [5, 10, 10, -20, -20, 10, 10, 5],
    [0, 0, 0, 0, 0, 0, 0, 0]
  ],
  n: [
    [-50, -40, -30, -30, -30, -30, -40, -50],
    [-40, -20, 0, 5, 5, 0, -20, -40],
    [-30, 5, 10, 15, 15, 10, 5, -30],
    [-30, 0, 15, 20, 20, 15, 0, -30],
    [-30, 5, 15, 20, 20, 15, 5, -30],
    [-30, 0, 10, 15, 15, 10, 0, -30],
    [-40, -20, 0, 0, 0, 0, -20, -40],
    [-50, -40, -30, -30, -30, -30, -40, -50]
  ],
  b: [
    [-20, -10, -10, -10, -10, -10, -10, -20],
    [-10, 5, 0, 0, 0, 0, 5, -10],
    [-10, 10, 10, 10, 10, 10, 10, -10],
    [-10, 0, 10, 10, 10, 10, 0, -10],
    [-10, 5, 5, 10, 10, 5, 5, -10],
    [-10, 0, 5, 10, 10, 5, 0, -10],
    [-10, 0, 0, 0, 0, 0, 0, -10],
    [-20, -10, -10, -10, -10, -10, -10, -20]
  ],
  r: [
    [0, 0, 5, 10, 10, 5, 0, 0],
    [-5, 0, 0, 0, 0, 0, 0, -5],
    [-5, 0, 0, 0, 0, 0, 0, -5],
    [-5, 0, 0, 0, 0, 0, 0, -5],
    [-5, 0, 0, 0, 0, 0, 0, -5],
    [-5, 0, 0, 0, 0, 0, 0, -5],
    [5, 10, 10, 10, 10, 10, 10, 5],
    [0, 0, 0, 0, 0, 0, 0, 0]
  ],
  q: [
    [-20, -10, -10, -5, -5, -10, -10, -20],
    [-10, 0, 5, 0, 0, 0, 0, -10],
    [-10, 5, 5, 5, 5, 5, 0, -10],
    [0, 0, 5, 5, 5, 5, 0, -5],
    [-5, 0, 5, 5, 5, 5, 0, -5],
    [-10, 0, 5, 5, 5, 5, 0, -10],
    [-10, 0, 0, 0, 0, 0, 0, -10],
    [-20, -10, -10, -5, -5, -10, -10, -20]
  ],
  k: [
    [-30, -40, -40, -50, -50, -40, -40, -30],
    [-30, -40, -40, -50, -50, -40, -40, -30],
    [-30, -40, -40, -50, -50, -40, -40, -30],
    [-30, -40, -40, -50, -50, -40, -40, -30],
    [-20, -30, -30, -40, -40, -30, -30, -20],
    [-10, -20, -20, -20, -20, -20, -20, -10],
    [20, 20, 0, 0, 0, 0, 20, 20],
    [20, 30, 10, 0, 0, 10, 30, 20]
  ]
};

function squareName(rankIndex, fileIndex) {
  const file = String.fromCharCode(97 + fileIndex);
  const rank = 8 - rankIndex;
  return `${file}${rank}`;
}

function renderBoard() {
  boardEl.innerHTML = "";
  const board = chess.board();

  board.forEach((rank, rankIndex) => {
    rank.forEach((piece, fileIndex) => {
      const square = squareName(rankIndex, fileIndex);
      const button = document.createElement("button");
      button.className = `square ${(rankIndex + fileIndex) % 2 === 0 ? "light" : "dark"}`;
      button.dataset.square = square;
      button.type = "button";

      if (piece) {
        const pieceEl = document.createElement("span");
        pieceEl.className = "piece";
        pieceEl.textContent = pieces[`${piece.color}${piece.type}`];
        button.append(pieceEl);
      }

      if (selectedSquare === square) {
        button.classList.add("selected");
      }

      if (lastMoveSquares.includes(square)) {
        button.classList.add("last-move");
      }

      const legalMove = legalTargets.find((move) => move.to === square);
      if (legalMove) {
        button.classList.add(legalMove.captured ? "capture" : "legal");
      }

      button.addEventListener("click", () => onSquareClick(square));
      boardEl.append(button);
    });
  });

  updateStatus();
}

function onSquareClick(square) {
  if (aiThinking || chess.isGameOver() || chess.turn() !== "w") return;

  const clickedPiece = chess.get(square);
  if (clickedPiece?.color === "w") {
    selectedSquare = square;
    legalTargets = chess.moves({ square, verbose: true });
    renderBoard();
    return;
  }

  const selectedMove = legalTargets.find((move) => move.to === square);
  if (!selectedMove) return;

  makeMove(selectedMove);
  selectedSquare = null;
  legalTargets = [];
  renderBoard();

  if (!chess.isGameOver()) {
    window.setTimeout(makeComputerMove, 120);
  }
}

function makeMove(move) {
  const result = chess.move({
    from: move.from,
    to: move.to,
    promotion: move.promotion || "q"
  });
  if (result) {
    lastMoveSquares = [result.from, result.to];
  }
}

function tryMoveSilently(move) {
  return chess.move({
    from: move.from,
    to: move.to,
    promotion: move.promotion || "q"
  });
}

function makeComputerMove() {
  aiThinking = true;
  updateStatus("Der Computer denkt...", true);

  window.setTimeout(() => {
    try {
      const bestMove = findBestMove(currentDifficulty);
      if (bestMove) {
        makeMove(bestMove);
      }
    } catch (error) {
      console.error("KI-Zug fehlgeschlagen:", error);
      const fallbackMove = findFastMove();
      if (fallbackMove) {
        makeMove(fallbackMove);
      }
    } finally {
      aiThinking = false;
      renderBoard();
    }
  }, 40);
}

function findBestMove(depth) {
  searchDeadline = performance.now() + (TIME_LIMIT_BY_DEPTH[depth] || 650);
  let bestMove = findFastMove();

  for (let currentDepth = 1; currentDepth <= depth; currentDepth += 1) {
    if (isSearchTimedOut()) break;
    const result = searchRoot(currentDepth);
    if (result.bestMove) {
      bestMove = result.bestMove;
    }
    if (result.timedOut) break;
  }

  return bestMove || chess.moves({ verbose: true })[0];
}

function findFastMove() {
  const moves = orderMoves(chess.moves({ verbose: true }));
  return moves[0] || null;
}

function searchRoot(depth) {
  const moves = orderMoves(chess.moves({ verbose: true }));
  let bestMove = null;
  let bestScore = Number.NEGATIVE_INFINITY;
  let alpha = Number.NEGATIVE_INFINITY;
  const beta = Number.POSITIVE_INFINITY;
  let timedOut = false;

  for (const move of moves) {
    if (isSearchTimedOut()) {
      timedOut = true;
      break;
    }

    tryMoveSilently(move);
    const score = search(depth - 1, alpha, beta, false);
    chess.undo();

    if (isSearchTimedOut()) {
      timedOut = true;
      break;
    }

    if (score > bestScore) {
      bestScore = score;
      bestMove = move;
    }

    alpha = Math.max(alpha, bestScore);
  }

  return { bestMove: bestMove || moves[0], timedOut };
}

function isSearchTimedOut() {
  return performance.now() >= searchDeadline;
}

function search(depth, alpha, beta, maximizing) {
  if (isSearchTimedOut()) return evaluate();

  if (chess.isCheckmate()) {
    return chess.turn() === "b" ? -100000 - depth : 100000 + depth;
  }

  if (chess.isDraw() || chess.isStalemate() || chess.isThreefoldRepetition() || chess.isInsufficientMaterial()) {
    return 0;
  }

  if (depth <= 0) {
    return evaluate();
  }

  const moves = orderMoves(chess.moves({ verbose: true }));

  if (maximizing) {
    let best = Number.NEGATIVE_INFINITY;
    for (const move of moves) {
      tryMoveSilently(move);
      best = Math.max(best, search(depth - 1, alpha, beta, false));
      chess.undo();
      alpha = Math.max(alpha, best);
      if (beta <= alpha) break;
    }
    return best;
  }

  let best = Number.POSITIVE_INFINITY;
  for (const move of moves) {
    tryMoveSilently(move);
    best = Math.min(best, search(depth - 1, alpha, beta, true));
    chess.undo();
    beta = Math.min(beta, best);
    if (beta <= alpha) break;
  }
  return best;
}

function evaluate() {
  const board = chess.board();
  let score = 0;

  board.forEach((rank, rankIndex) => {
    rank.forEach((piece, fileIndex) => {
      if (!piece) return;
      const tableRank = piece.color === "w" ? rankIndex : 7 - rankIndex;
      const value = pieceValue[piece.type] + pst[piece.type][tableRank][fileIndex];
      score += piece.color === "b" ? value : -value;
    });
  });

  if (chess.inCheck()) {
    score += chess.turn() === "w" ? 35 : -35;
  }

  return score;
}

function orderMoves(moves) {
  return moves.sort((a, b) => moveScore(b) - moveScore(a));
}

function moveScore(move) {
  let score = 0;
  if (move.captured) score += 10 * pieceValue[move.captured] - pieceValue[move.piece];
  if (move.promotion) score += pieceValue[move.promotion];
  if (move.san.includes("+")) score += 40;
  if (move.san.includes("#")) score += 100000;
  return score;
}

function updateStatus(customText = "", thinking = false) {
  statusText.classList.toggle("thinking", thinking);

  if (customText) {
    statusText.textContent = customText;
    return;
  }

  if (chess.isCheckmate()) {
    statusText.textContent = chess.turn() === "w" ? "Schachmatt. Computer gewinnt." : "Schachmatt. Du gewinnst.";
    hintText.textContent = "Starte ein neues Spiel, um nochmals zu spielen.";
    return;
  }

  if (chess.isDraw() || chess.isStalemate()) {
    statusText.textContent = "Remis.";
    hintText.textContent = "Das Spiel ist beendet.";
    return;
  }

  if (chess.inCheck()) {
    statusText.textContent = chess.turn() === "w" ? "Du bist im Schach." : "Computer ist im Schach.";
    hintText.textContent = chess.turn() === "w" ? "Finde einen legalen Zug aus dem Schach." : "Der Computer sucht eine Antwort.";
    return;
  }

  statusText.textContent = chess.turn() === "w" ? "Du bist am Zug." : "Computer ist am Zug.";
  hintText.textContent = selectedSquare ? "Wähle ein markiertes Zielfeld." : "Klicke eine weisse Figur an und danach ein Zielfeld.";
}

function resetGame() {
  chess.reset();
  selectedSquare = null;
  legalTargets = [];
  aiThinking = false;
  lastMoveSquares = [];
  renderBoard();
}

function openGame() {
  currentDifficulty = Number(startDifficulty.value);
  newGameDifficulty.value = String(currentDifficulty);
  startScreen.classList.add("is-hidden");
  gameScreen.classList.remove("is-hidden");
  resetGame();
}

function openSettings() {
  colorThemeSelect.value = currentTheme;
  nightModeToggle.checked = document.body.classList.contains("night-mode");
  settingsDialog.showModal();
}

function openNewGameDialog() {
  newGameDifficulty.value = String(currentDifficulty);
  newGameDialog.showModal();
}

function applyTheme(theme) {
  currentTheme = theme;
  document.body.classList.toggle("theme-green", theme === "green");
  document.body.classList.toggle("theme-brown", theme === "brown");
}

function applyNightMode(enabled) {
  document.body.classList.toggle("night-mode", enabled);
}

startGameBtn.addEventListener("click", openGame);

settingsBtn.addEventListener("click", () => {
  currentDifficulty = Number(startDifficulty.value);
  openSettings();
});

openSettingsBtn.addEventListener("click", openSettings);

closeSettingsBtn.addEventListener("click", () => settingsDialog.close());

closeNewGameBtn.addEventListener("click", () => newGameDialog.close());

newGameBtn.addEventListener("click", openNewGameDialog);

confirmNewGameBtn.addEventListener("click", () => {
  currentDifficulty = Number(newGameDifficulty.value);
  startDifficulty.value = String(currentDifficulty);
  newGameDialog.close();
  resetGame();
});

startDifficulty.addEventListener("change", () => {
  currentDifficulty = Number(startDifficulty.value);
  newGameDifficulty.value = String(currentDifficulty);
});

colorThemeSelect.addEventListener("change", () => {
  applyTheme(colorThemeSelect.value);
});

nightModeToggle.addEventListener("change", () => {
  applyNightMode(nightModeToggle.checked);
});

renderBoard();
