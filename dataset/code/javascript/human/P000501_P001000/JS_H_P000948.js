// =============================================================================
// game.ejs page script
// -----------------------------------------------------------------------------
// Powers the "Game Review" page: shows a previously-played game move by move,
// annotates blunders/mistakes, lets the user step through with arrow keys or
// use "Walk Through" to auto-play the whole game with spoken commentary and
// engine-suggested best lines for bad moves.
//
// Depends on globals from shared scripts loaded via views/partials/head.ejs:
//   - jQuery ($), Chess, Chessboard
//   - drawGraph, showPromotionMenu, commonOnDragStart, commonOnSnapEnd,
//     flipBoard, playMoveSound  -> custom.chess.js
//   - fetchAnalysis, stockfishFetchAnalysis -> stockfish.js
//   - speak, speakMove, pvToSpeech          -> move2Speech.js
//
// Server-provided data (game info, move list, starting FEN) is injected via
// `window.MAGNUS_PAGE_DATA` by a small inline <script> in game.ejs, because
// EJS templating can't run inside a static .js file.
// =============================================================================

// `info` is an array with one row of metadata about this game (players,
// result, time control, opening, etc). `mainLine` is the array of moves
// that were actually played, each annotated with eval/loss/check/mate info.
const info     = window.MAGNUS_PAGE_DATA.info;
const mainLine = window.MAGNUS_PAGE_DATA.moves;

// FEN of the position before the first move (usually the standard start).
const startFen = window.MAGNUS_PAGE_DATA.startFen;

// -- Page state ---------------------------------------------------------------
// currentIndex: -1 means "showing the start position"; otherwise it is the
// index into mainLine of the move currently displayed.
let currentIndex = -1;
let board = null;
let game = new Chess();

// Tracks the current "extra" Stockfish analysis request (separate from the
// game's own pre-computed eval data) so it can be cancelled if the user
// navigates away before it finishes.
let currentAnalysisAbortController = null;

// Walkthrough state: whether auto-play is running, paused, or has been
// asked to stop.
let isWalkingThrough = false;
let isPaused = false;
let isStopped = false;

// Used to build the "the best move was ..." commentary when a blunder is
// immediately followed by another blunder during the walkthrough.
window.currentBestLineSpeech = '';
window.previousBestLine = '';

// `info[0]` has this game's player names/ratings, used to label the board.
// Built once here so flipBoard always re-renders from this authoritative
// data instead of swapping whatever currently happens to be on screen.
const whitePlayer = (info && info[0]) ? { name: info[0].white, elo: info[0].white_elo } : { name: '', elo: '' };
const blackPlayer = (info && info[0]) ? { name: info[0].black, elo: info[0].black_elo } : { name: '', elo: '' };

// Writes a player's name/rating into the #top_player / #bottom_player
// labels above and below the board. Passed to flipBoard (custom.chess.js)
// so the labels stay in sync whenever the board is flipped.
function renderPlayerLabels(topPlayer, bottomPlayer) {
  $('#top_player').html(`<strong>${topPlayer.name}</strong> (${topPlayer.elo})`);
  $('#bottom_player').html(`<strong>${bottomPlayer.name}</strong> (${bottomPlayer.elo})`);
}

// Flips the board and its player labels together (see custom.chess.js).
function rotate() {
  flipBoard(board, whitePlayer, blackPlayer, renderPlayerLabels);
}

// Refreshes the board, evaluation label, move-quality indicator, move-list
// highlight, and eval graph to match `currentIndex`. Also kicks off a fresh
// engine analysis request for the current position.
// If `awaitAnalysis` is true, waits for that analysis to complete before
// returning (used during the walkthrough so timing stays predictable).
async function updateUI(awaitAnalysis = false) {
        const currentFen = currentIndex === -1 ? startFen : mainLine[currentIndex].fen;
        const currentEval = currentIndex === -1 ? 0 : mainLine[currentIndex].final_eval;

        const isCheck = currentIndex === -1 ? 0 : mainLine[currentIndex].incheck;
        const isMate  = currentIndex === -1 ? 0 : mainLine[currentIndex].mate;
 
        board.position(currentFen);
        game.load(currentFen);
        $('#fen-text').text('FEN: ' + currentFen);

        if (isMate === 1) {
          $('#evaluation').text('Eval: Mate');
        } else if (isCheck === 1) {
          $('#evaluation').text('Eval: Check');
        } else {
          $('#evaluation').text('Eval: ' + currentEval);
        }

        // Show move quality annotation (Blunder / Mistake) for any move,
        // regardless of which side made it, so the info bar reflects both players.
        let moveInfoText = '';
        if (currentIndex !== -1) {
          const move = mainLine[currentIndex];
          if (move.loss === 3) moveInfoText = 'Blunder';
          else if (move.loss === 2) moveInfoText = 'Mistake';
        }
        $('#move-info').text(moveInfoText);

        $('.move-item').removeClass('active');
        $(`#move-${currentIndex + 1}`).addClass('active');

        drawGraph('graph', [0, ...mainLine.map(m => (m.incheck !== 0 || m.mate !== 0) ? null : parseFloat(m.final_eval))], currentIndex);
        if (awaitAnalysis) {
          await fetchAnalysis(currentFen);
        } else {
          fetchAnalysis(currentFen);
        }
    }

    // Navigates to a given move index (-1 = start), updates the UI, and
    // speaks the move. If the move just navigated to was a blunder/mistake,
    // also speaks a short comment naming the error and (if known) the best
    // alternative move from the previous analysis.
    // `fromWalkThrough` is passed through to updateUI's awaitAnalysis flag
    // so the walkthrough can wait for analysis before moving on.
    async function goToMove(index, fromWalkThrough = false) {
        if (isWalkingThrough && !fromWalkThrough) return;
        if (index >= -1 && index < mainLine.length) {
            window.previousBestLine = window.currentBestLineSpeech;
            const prevFen = currentIndex === -1 ? startFen : mainLine[currentIndex].fen;
            currentIndex = index;
            await updateUI(fromWalkThrough);
            playMoveSound();
            if (currentIndex !== -1) {
              const move = mainLine[currentIndex];
              await speakMove(prevFen, move.short_notation);

              if (move.loss === 2 || move.loss === 3) {
                const label = move.loss === 3 ? "blunder" : "mistake";
                let comment = `This was a ${label}.`;
                if (window.previousBestLine) {
                  comment += " The best move was " + window.previousBestLine;
                }
                await speak(comment);
              }
            }
        }
    }
    

    // Called when the user picks a promotion piece from the promotion menu
    // while exploring "what if" moves on the board (this is a free-analysis
    // sandbox separate from the recorded mainLine). Completes the move and
    // requests fresh engine analysis for the resulting position.
    function finalizePromotion(source, target, piece) {
      $('#promotion-layer').hide();
      const fenBefore = game.fen();
      const move = game.move({ from: source, to: target, promotion: piece });
      board.position(game.fen());
      playMoveSound();
      speakMove(fenBefore, move);
      const currentFen = game.fen();
      $('#fen-text').text('FEN (Analysis): ' + currentFen);
      fetchAnalysis(currentFen);
    }

    // chessboard.js callback for free-analysis moves the user makes by
    // dragging pieces (independent of the recorded game). Handles pawn
    // promotion via the shared handlePromotionDrop helper (custom.chess.js),
    // otherwise plays the move and requests fresh engine analysis for the
    // new position.
    function onDrop (source, target) {
        const promotionStatus = handlePromotionDrop(game, source, target, finalizePromotion);
        if (promotionStatus === 'illegal') return 'snapback';
        if (promotionStatus === 'pending') return;

        const fenBefore = game.fen();
        let move = game.move({ from: source, to: target });
        if (move === null) return 'snapback';
        playMoveSound();
        speakMove(fenBefore, move);
        const currentFen = game.fen();
        $('#fen-text').text('FEN (Analysis): ' + currentFen);
        fetchAnalysis(currentFen);
    }

    // chessboard.js configuration. Dragging is disabled while a walkthrough
    // is running so the auto-play can't be interrupted by accidental moves.
    const config = {
        draggable: true,
        position: startFen,
        onDragStart: (source, piece) => {
          if (isWalkingThrough) return false;
          return commonOnDragStart(source, piece, game);
        },
        onDrop: onDrop,
        onSnapEnd: () => commonOnSnapEnd(board, game),
        pieceTheme: '/img/{piece}.png'
    };

    board = Chessboard('myBoard', config);
    
    $(window).on('resize', board.resize);

    // If the recorded game was played from Black's perspective (side == 0),
    // flip the board so it matches how the player originally viewed it.
    if (info && info[0].side == 0) rotate();
    $('#flipBoardBtn').on('click', rotate);

    // ─────────────────────────────────────────────────────────────────────────
    // smartWait: pauses walkthrough for `ms` milliseconds, but respects the
    // pause/stop buttons. Resolves immediately when isStopped is set.
    // ─────────────────────────────────────────────────────────────────────────
    function smartWait(ms) {
      return new Promise(resolve => {
        let remaining = ms;
        let lastTick = Date.now();
        const check = setInterval(() => {
          if (isStopped) {
            clearInterval(check);
            resolve();
            return;
          }
          const now = Date.now();
          if (!isPaused) {
            remaining -= (now - lastTick);
            if (remaining <= 0) {
              clearInterval(check);
              resolve();
            }
          }
          lastTick = now;
        }, 100);
      });
    }

    // ─────────────────────────────────────────────────────────────────────────
    // getBestLineFromStockfish: asks the engine for the best continuation
    // from the given FEN. Returns an array of UCI move strings (e.g. ["e2e4", "e7e5"]).
    // Returns [] if analysis fails or is stopped.
    // ─────────────────────────────────────────────────────────────────────────
    async function getBestLineFromStockfish(fen) {
      try {
        const abortController = new AbortController();
        const data = await stockfishFetchAnalysis(fen, abortController.signal);

        if (!data.lines || data.lines.length === 0) return [];

        // line.pv is a space-separated string of UCI moves, e.g. "e2e4 e7e5 g1f3"
        // multipv === 1 is the engine's top-ranked best line
        const bestLine = data.lines.find(l => l.multipv === 1);
        if (!bestLine || !bestLine.pv) return [];

        return bestLine.pv.trim().split(' ').filter(Boolean);
      } catch (err) {
        console.error('Best line fetch failed:', err);
        return [];
      }
    }

    // ─────────────────────────────────────────────────────────────────────────
    // playBestLine: visually animates the engine's best line on the board.
    //
    // How it works:
    //   1. We start from `fenBeforeBlunder` — the position BEFORE the bad move.
    //      (The user already played their bad move; we rewind to show what
    //       should have happened instead.)
    //   2. We ask Stockfish for the best continuation from that position.
    //   3. We use chess.js to apply each UCI move and get the resulting FEN,
    //      then update the board so the user sees the pieces move.
    //   4. After all best-line moves are shown, we restore the board back to
    //      the position where the main game left off (after the blunder).
    // ─────────────────────────────────────────────────────────────────────────
    async function playBestLine(fenBeforeBlunder, fenAfterBlunder) {
      if (isStopped) return;

      // Announce that we're about to show the best line
      await speak("Here is what the engine recommends instead.");
      if (isStopped) return;

      // Show a visual indicator that we're in "best line" mode
      $('#move-info').text('Best Line ▶');

      // Fetch the best move sequence from Stockfish, capped at 5 moves
      const bestMoves = (await getBestLineFromStockfish(fenBeforeBlunder)).slice(0, 5);

      if (bestMoves.length === 0 || isStopped) {
        // Nothing to show — restore board to after-blunder position and return
        board.position(fenAfterBlunder);
        game.load(fenAfterBlunder);
        return;
      }

      // Build spoken description of the full best line before playing it
      const bestLineSpeech = pvToSpeech(fenBeforeBlunder, bestMoves.join(' '));

      // ── Rewind the board to the position before the blunder ──────────────
      // We move the board back visually so the user sees the best line
      // starting from the correct position.
      board.position(fenBeforeBlunder);
      game.load(fenBeforeBlunder);
      await smartWait(600); // brief pause so user sees the rewind
      if (isStopped) {
        board.position(fenAfterBlunder);
        game.load(fenAfterBlunder);
        return;
      }

      // ── Play each best-line move one by one ───────────────────────────────
      // We use a temporary chess.js instance so we don't corrupt mainLine state.
      const tempGame = new Chess(fenBeforeBlunder);
      const delay = parseInt($('#walkthrough-delay').val()) * 1000;

      for (const uciMove of bestMoves) {
        if (isStopped) break;

        const currentFen = tempGame.fen();

        // Apply the UCI move (format: "e2e4" or "e7e8q" for promotion)
        const moveResult = tempGame.move({
          from: uciMove.substring(0, 2),
          to:   uciMove.substring(2, 4),
          promotion: uciMove.substring(4, 5) || 'q'
        });

        if (!moveResult) {
          // If the move is illegal (shouldn't happen), stop the best-line replay
          console.warn('Best line move was illegal:', uciMove, 'in FEN:', currentFen);
          break;
        }

        // Show the new position on the board
        const newFen = tempGame.fen();
        board.position(newFen);
        game.load(newFen);
        $('#fen-text').text('FEN (Best Line): ' + newFen);
        playMoveSound();

        // Speak each individual best-line move
        await speakMove(currentFen, uciMove);
        if (isStopped) break;

        // Wait before showing the next move in the best line
        await smartWait(delay);
        if (isStopped) break;
      }

      // Speak the full best-line description after playing through it
      if (!isStopped && bestLineSpeech) {
        await speak("Best line: " + bestLineSpeech);
      }

      // ── Restore the board to the actual game position (after the blunder) ─
      // The main walkthrough will continue from here.
      board.position(fenAfterBlunder);
      game.load(fenAfterBlunder);
      $('#fen-text').text('FEN: ' + fenAfterBlunder);
      $('#move-info').text(
        mainLine[currentIndex] && mainLine[currentIndex].loss === 3 ? 'Blunder' : 'Mistake'
      );

      // Small pause before continuing with the main game
      await smartWait(800);
    }

    // ─────────────────────────────────────────────────────────────────────────
    // startWalkThrough: steps through every move in the game.
    // When a blunder or mistake is encountered:
    //   1. Announce the error and name the best move (existing behaviour).
    //   2. Call playBestLine() to visually demonstrate the engine's suggestion.
    //   3. Continue the main game from where it left off.
    // ─────────────────────────────────────────────────────────────────────────
    async function startWalkThrough() {
      if (isWalkingThrough) return;
      isWalkingThrough = true;
      isPaused = false;
      isStopped = false;
      $('#walkThroughBtn').prop('disabled', true);
      $('#pauseWalkthroughBtn').text('Pause');
      $('#walkthrough-delay-container').css('display', 'flex');

      try {
        // Reset to the start position
        await goToMove(-1, true);
        if (isStopped) return;

        for (let i = 0; i < mainLine.length; i++) {
          const delay = parseInt($('#walkthrough-delay').val()) * 1000;
          await smartWait(delay);
          if (isStopped) break;

          // The FEN before this move is played (used as starting point for best line)
          const fenBeforeThisMove = currentIndex === -1
            ? startFen
            : mainLine[currentIndex].fen;

          // Move to this position in the main game
          await goToMove(i, true);
          if (isStopped) break;

          const move = mainLine[i];
          const isBlunderOrMistake = move.loss === 2 || move.loss === 3;

          if (isBlunderOrMistake) {
            // fenAfterBlunder is the position AFTER the bad move was played.
            // This is what the board is currently showing (mainLine[i].fen).
            const fenAfterBlunder = mainLine[i].fen;

            // Show the engine's best line starting from before the blunder.
            // After playBestLine() finishes, the board is restored to fenAfterBlunder.
            await playBestLine(fenBeforeThisMove, fenAfterBlunder);
            if (isStopped) break;
          }
        }
      } finally {
        isWalkingThrough = false;
        $('#walkThroughBtn').prop('disabled', false);
        $('#walkthrough-delay-container').hide();
        if (isStopped) {
          await goToMove(-1, true);
        }
      }
    }

    // "Walk Through" button starts the automated playback of the whole game.
    $('#walkThroughBtn').on('click', startWalkThrough);

    // "Pause"/"Continue" toggles the walkthrough timer and the speech
    // synthesis playback together, so narration and board movement stay
    // in sync.
    $('#pauseWalkthroughBtn').on('click', function() {
      isPaused = !isPaused;
      $(this).text(isPaused ? 'Continue' : 'Pause');
      if (isPaused) {
        window.speechSynthesis.pause();
      } else {
        window.speechSynthesis.resume();
      }
    });

    // "Stop" cancels the walkthrough entirely and silences any speech.
    // The walkthrough loop checks `isStopped` and unwinds gracefully.
    $('#stopWalkthroughBtn').on('click', function() {
      isStopped = true;
      isPaused = false;
      window.speechSynthesis.cancel();
    });

    // Restore the user's previously-chosen walkthrough delay (seconds
    // between moves) from localStorage, and persist it whenever they
    // adjust the slider.
    $(document).ready(() => {
      const savedDelay = localStorage.getItem('magnus-walkthrough-delay') || 5;
      $('#walkthrough-delay').val(savedDelay);
      $('#delay-value').text(savedDelay);

      $('#walkthrough-delay').on('input', function() {
        const val = $(this).val();
        $('#delay-value').text(val);
        localStorage.setItem('magnus-walkthrough-delay', val);
      });
    });

    // Initial render: show the starting position.
    updateUI();   

    // Left/Right arrow keys step backward/forward through the game, but are
    // disabled during an automated walkthrough or while a move is being
    // spoken aloud (to avoid overlapping/garbled narration).
    $(document).keydown(async e => {
        if (isWalkingThrough) return;
        const isSoundEnabled = localStorage.getItem('magnus-sound-enabled') !== 'false';
        if (isSoundEnabled && window.speechSynthesis.speaking) return;

        if (e.keyCode == 37) await goToMove(currentIndex - 1);
        if (e.keyCode == 39) await goToMove(currentIndex + 1);
    });
