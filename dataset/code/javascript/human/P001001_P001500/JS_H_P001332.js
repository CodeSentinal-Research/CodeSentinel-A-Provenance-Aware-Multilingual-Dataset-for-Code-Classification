/* =========================================================
   Smart Form Validator — validator.js
   Beginner-friendly: every section is clearly explained
   ========================================================= */

/* ----------------------------------------------------------
   STEP NAVIGATION
   currentStep tracks which step (1, 2, or 3) the user is on.
   ---------------------------------------------------------- */
let currentStep = 1;

/**
 * goToStep(targetStep)
 * ---------------------
 * Called when the user clicks "Next Step" or "Back".
 * 1. Validate the fields of the CURRENT step.
 * 2. If validation passes → hide current step, show next step.
 * 3. Update the progress dots at the top.
 */
function goToStep(targetStep) {
  // Only validate when going FORWARD (not when going back)
  if (targetStep > currentStep) {
    const isValid = validateStep(currentStep);
    if (!isValid) return;          // stop here if there are errors
  }

  // Hide the currently visible step
  document.getElementById('step' + currentStep).classList.add('d-none');

  // Show the target step
  document.getElementById('step' + targetStep).classList.remove('d-none');

  // If moving to step 3 → fill in the review summary
  if (targetStep === 3) {
    fillSummary();
  }

  // Update progress bar dots
  updateStepBar(targetStep);

  // Remember where we are
  currentStep = targetStep;
}

/* ----------------------------------------------------------
   STEP BAR UPDATE
   ---------------------------------------------------------- */

/**
 * updateStepBar(activeStep)
 * --------------------------
 * Marks steps as: active (current), done (completed), or default.
 * Also colours the lines between dots.
 */
function updateStepBar(activeStep) {
  const dots  = [
    document.getElementById('step1dot'),
    document.getElementById('step2dot'),
    document.getElementById('step3dot'),
  ];
  const lines = document.querySelectorAll('.step-line');

  dots.forEach(function(dot, index) {
    const stepNumber = index + 1;
    dot.classList.remove('active', 'done');

    if (stepNumber < activeStep) {
      dot.classList.add('done');
      // Replace the number with a checkmark inside the dot
      dot.querySelector('.step-dot').innerHTML = '<i class="bi bi-check-lg"></i>';
    } else if (stepNumber === activeStep) {
      dot.classList.add('active');
      dot.querySelector('.step-dot').textContent = stepNumber;
    } else {
      dot.querySelector('.step-dot').textContent = stepNumber;
    }
  });

  // Colour the lines between steps
  lines.forEach(function(line, index) {
    if (index + 1 < activeStep) {
      line.classList.add('done');
    } else {
      line.classList.remove('done');
    }
  });
}

/* ----------------------------------------------------------
   VALIDATION — MAIN FUNCTION
   ---------------------------------------------------------- */

/**
 * validateStep(step)
 * -------------------
 * Validates all fields that belong to the given step number.
 * Returns true if ALL fields are valid, false otherwise.
 */
function validateStep(step) {
  let allValid = true;

  if (step === 1) {
    // Validate each field; && keeps allValid false if ANY fails
    if (!validateFullName())  allValid = false;
    if (!validateEmail())     allValid = false;
    if (!validatePhone())     allValid = false;
  }

  if (step === 2) {
    if (!validateUsername())  allValid = false;
    if (!validatePassword())  allValid = false;
    if (!validateConfirmPw()) allValid = false;
  }

  return allValid;
}

/* ----------------------------------------------------------
   INDIVIDUAL FIELD VALIDATORS
   Each function returns true (valid) or false (invalid).
   ---------------------------------------------------------- */

/** Full Name: required, at least 2 words */
function validateFullName() {
  const input = document.getElementById('fullName');
  const value = input.value.trim();

  if (value === '') {
    showError(input, 'fullNameError', 'Please enter your full name.');
    return false;
  }

  // Check that there are at least two words (first + last name)
  const words = value.split(' ').filter(function(w) { return w.length > 0; });
  if (words.length < 2) {
    showError(input, 'fullNameError', 'Please enter at least a first and last name.');
    return false;
  }

  showSuccess(input, 'fullNameError');
  return true;
}

/** Email: required, must match email format */
function validateEmail() {
  const input = document.getElementById('email');
  const value = input.value.trim();

  if (value === '') {
    showError(input, 'emailError', 'Please enter your email address.');
    return false;
  }

  // Simple email regex pattern: something@something.something
  const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  if (!emailPattern.test(value)) {
    showError(input, 'emailError', 'Please enter a valid email address.');
    return false;
  }

  showSuccess(input, 'emailError');
  return true;
}

/** Phone: required, only digits/spaces/+/- and 7–15 characters */
function validatePhone() {
  const input = document.getElementById('phone');
  const value = input.value.trim();

  if (value === '') {
    showError(input, 'phoneError', 'Please enter your phone number.');
    return false;
  }

  // Remove spaces, dashes, parentheses before counting digits
  const digitsOnly = value.replace(/[\s\-\(\)]/g, '');
  const phonePattern = /^\+?[0-9]{7,15}$/;

  if (!phonePattern.test(digitsOnly)) {
    showError(input, 'phoneError', 'Please enter a valid phone number (7–15 digits).');
    return false;
  }

  showSuccess(input, 'phoneError');
  return true;
}

/** Username: required, 3–20 chars, letters/numbers/_ or - only */
function validateUsername() {
  const input = document.getElementById('username');
  const value = input.value.trim();

  if (value === '') {
    showError(input, 'usernameError', 'Please choose a username.');
    return false;
  }

  if (value.length < 3 || value.length > 20) {
    showError(input, 'usernameError', 'Username must be between 3 and 20 characters.');
    return false;
  }

  const usernamePattern = /^[a-zA-Z0-9_\-]+$/;
  if (!usernamePattern.test(value)) {
    showError(input, 'usernameError', 'Only letters, numbers, underscores and hyphens allowed.');
    return false;
  }

  showSuccess(input, 'usernameError');
  return true;
}

/** Password: required, minimum 8 chars, must have letter + number */
function validatePassword() {
  const input = document.getElementById('password');
  const value = input.value;

  if (value === '') {
    showError(input, 'passwordError', 'Please create a password.');
    return false;
  }

  if (value.length < 8) {
    showError(input, 'passwordError', 'Password must be at least 8 characters.');
    return false;
  }

  const hasLetter = /[a-zA-Z]/.test(value);
  const hasNumber = /[0-9]/.test(value);

  if (!hasLetter || !hasNumber) {
    showError(input, 'passwordError', 'Password must include at least one letter and one number.');
    return false;
  }

  showSuccess(input, 'passwordError');
  return true;
}

/** Confirm Password: must match the password field */
function validateConfirmPw() {
  const pwInput    = document.getElementById('password');
  const cpwInput   = document.getElementById('confirmPw');
  const pwValue    = pwInput.value;
  const cpwValue   = cpwInput.value;

  if (cpwValue === '') {
    showError(cpwInput, 'confirmPwError', 'Please confirm your password.');
    return false;
  }

  if (pwValue !== cpwValue) {
    showError(cpwInput, 'confirmPwError', 'Passwords do not match.');
    return false;
  }

  showSuccess(cpwInput, 'confirmPwError');
  return true;
}

/* ----------------------------------------------------------
   HELPER FUNCTIONS: showError / showSuccess / clearField
   ---------------------------------------------------------- */

/**
 * showError(inputEl, errorId, message)
 * -------------------------------------
 * Adds a red border to the input and displays the error message below it.
 */
function showError(inputEl, errorId, message) {
  inputEl.classList.remove('is-valid-custom');
  inputEl.classList.add('is-invalid-custom');

  const errorEl = document.getElementById(errorId);
  errorEl.innerHTML = '<i class="bi bi-exclamation-circle-fill"></i> ' + message;
}

/**
 * showSuccess(inputEl, errorId)
 * ------------------------------
 * Adds a green border to the input and clears the error message.
 */
function showSuccess(inputEl, errorId) {
  inputEl.classList.remove('is-invalid-custom');
  inputEl.classList.add('is-valid-custom');

  const errorEl = document.getElementById(errorId);
  errorEl.innerHTML = '';
}

/**
 * clearField(inputEl, errorId)
 * -----------------------------
 * Removes all validation styles (neutral state).
 */
function clearField(inputEl, errorId) {
  inputEl.classList.remove('is-valid-custom', 'is-invalid-custom');
  document.getElementById(errorId).innerHTML = '';
}

/* ----------------------------------------------------------
   REAL-TIME (LIVE) VALIDATION
   These event listeners fire as the user types, giving instant feedback.
   ---------------------------------------------------------- */

// Step 1 — Personal Info
document.getElementById('fullName').addEventListener('input', function() {
  if (this.value.trim() !== '') validateFullName();
  else clearField(this, 'fullNameError');
});

document.getElementById('email').addEventListener('input', function() {
  if (this.value.trim() !== '') validateEmail();
  else clearField(this, 'emailError');
});

document.getElementById('phone').addEventListener('input', function() {
  if (this.value.trim() !== '') validatePhone();
  else clearField(this, 'phoneError');
});

// Step 2 — Account Info
document.getElementById('username').addEventListener('input', function() {
  if (this.value.trim() !== '') validateUsername();
  else clearField(this, 'usernameError');
});

document.getElementById('password').addEventListener('input', function() {
  updateStrengthBar(this.value);   // live strength meter
  if (this.value !== '') validatePassword();
  else clearField(this, 'passwordError');

  // If confirm password already has a value → re-check match live
  if (document.getElementById('confirmPw').value !== '') validateConfirmPw();
});

document.getElementById('confirmPw').addEventListener('input', function() {
  if (this.value !== '') validateConfirmPw();
  else clearField(this, 'confirmPwError');
});

/* ----------------------------------------------------------
   PASSWORD STRENGTH METER
   ---------------------------------------------------------- */

/**
 * updateStrengthBar(password)
 * ----------------------------
 * Scores the password and updates the coloured bar + label.
 * Scoring (0–4 points):
 *   +1 if length >= 8
 *   +1 if has lowercase letter
 *   +1 if has uppercase letter
 *   +1 if has number
 *   +1 if has special character (!@#$…)
 */
function updateStrengthBar(password) {
  const fill  = document.getElementById('strengthFill');
  const label = document.getElementById('strengthLabel');

  if (password.length === 0) {
    fill.style.width      = '0%';
    fill.style.background = '';
    label.textContent     = '—';
    label.style.color     = '';
    return;
  }

  let score = 0;
  if (password.length >= 8)                    score++;
  if (/[a-z]/.test(password))                  score++;
  if (/[A-Z]/.test(password))                  score++;
  if (/[0-9]/.test(password))                  score++;
  if (/[^a-zA-Z0-9]/.test(password))           score++;

  // Map score (0–5) to percentage / colour / label
  const levels = [
    { pct: '10%', color: '#ff5c5c', text: 'Very weak' },
    { pct: '25%', color: '#ff5c5c', text: 'Weak'      },
    { pct: '50%', color: '#f0a500', text: 'Fair'      },
    { pct: '75%', color: '#f5c542', text: 'Good'      },
    { pct: '100%',color: '#3ecf8e', text: 'Strong'    },
  ];

  // Clamp score between 0 and 4 for indexing
  const level = levels[Math.min(score - 1, 4)] || levels[0];

  fill.style.width      = level.pct;
  fill.style.background = level.color;
  label.textContent     = level.text;
  label.style.color     = level.color;
}

/* ----------------------------------------------------------
   TOGGLE PASSWORD VISIBILITY
   ---------------------------------------------------------- */

/**
 * togglePassword(inputId, iconId)
 * --------------------------------
 * Switches an input between type="password" and type="text"
 * and swaps the eye / eye-slash icon accordingly.
 */
function togglePassword(inputId, iconId) {
  const inputEl = document.getElementById(inputId);
  const iconEl  = document.getElementById(iconId);

  if (inputEl.type === 'password') {
    inputEl.type      = 'text';
    iconEl.className  = 'bi bi-eye-slash';
  } else {
    inputEl.type      = 'password';
    iconEl.className  = 'bi bi-eye';
  }
}

/* ----------------------------------------------------------
   STEP 3 — FILL REVIEW SUMMARY
   ---------------------------------------------------------- */

/**
 * fillSummary()
 * --------------
 * Reads the field values and writes them into the Step 3 review card.
 */
function fillSummary() {
  document.getElementById('sName').textContent     = document.getElementById('fullName').value.trim();
  document.getElementById('sEmail').textContent    = document.getElementById('email').value.trim();
  document.getElementById('sPhone').textContent    = document.getElementById('phone').value.trim();
  document.getElementById('sUsername').textContent = document.getElementById('username').value.trim();
}

/* ----------------------------------------------------------
   FORM SUBMISSION
   ---------------------------------------------------------- */

/**
 * submitForm()
 * -------------
 * Validates the terms checkbox, then shows the success banner.
 */
function submitForm() {
  const termsCheckbox = document.getElementById('terms');
  const termsError    = document.getElementById('termsError');

  if (!termsCheckbox.checked) {
    termsError.innerHTML = '<i class="bi bi-exclamation-circle-fill"></i> You must agree to the Terms & Conditions.';
    return;
  }

  // Clear any previous error
  termsError.innerHTML = '';

  // Hide the form card
  document.querySelector('.form-card').classList.add('d-none');

  // Show the success banner
  document.getElementById('successBanner').classList.remove('d-none');
}

/* ----------------------------------------------------------
   RESET / START OVER
   ---------------------------------------------------------- */

/**
 * resetForm()
 * ------------
 * Clears all inputs, resets to step 1, hides success banner.
 */
function resetForm() {
  // Clear all text inputs
  document.querySelectorAll('.custom-input').forEach(function(input) {
    input.value = '';
    input.type  = input.id.includes('password') || input.id.includes('confirmPw')
                    ? 'password'   // reset password fields back to hidden
                    : input.type;
    input.classList.remove('is-valid-custom', 'is-invalid-custom');
  });

  // Clear all error messages
  document.querySelectorAll('.invalid-msg').forEach(function(el) {
    el.innerHTML = '';
  });

  // Reset strength bar
  document.getElementById('strengthFill').style.width = '0%';
  document.getElementById('strengthLabel').textContent = '—';

  // Uncheck terms
  document.getElementById('terms').checked = false;

  // Reset step eyes icons
  document.getElementById('pwEye').className  = 'bi bi-eye';
  document.getElementById('cpwEye').className = 'bi bi-eye';

  // Go back to step 1
  currentStep = 1;
  document.getElementById('step1').classList.remove('d-none');
  document.getElementById('step2').classList.add('d-none');
  document.getElementById('step3').classList.add('d-none');

  // Reset progress bar
  updateStepBar(1);
  // Restore dot numbers (they might have been replaced by checkmarks)
  document.querySelector('#step1dot .step-dot').textContent = '1';
  document.querySelector('#step2dot .step-dot').textContent = '2';
  document.querySelector('#step3dot .step-dot').textContent = '3';

  // Show the form card, hide success banner
  document.querySelector('.form-card').classList.remove('d-none');
  document.getElementById('successBanner').classList.add('d-none');
}
