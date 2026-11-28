/* ============================================================
   PRIYARAA — Handmade with Heart | BuilderFest Final
   main.js — All interactive behaviour
   Author  : Krishnapriya (Reg: 12402493)
   Version : 1.0.0
   ============================================================ */

/* ===== THEME TOGGLE ===== */
function toggleTheme() {
  const html = document.documentElement;
  const isDark = html.getAttribute('data-theme') === 'dark';
  html.setAttribute('data-theme', isDark ? 'light' : 'dark');
  const knob = document.querySelector('.theme-toggle .knob');
  knob.textContent = isDark ? '☀️' : '🌙';
  localStorage.setItem('priyaraa-theme', isDark ? 'light' : 'dark');
}

// Restore saved theme on load
(function () {
  const saved = localStorage.getItem('priyaraa-theme');
  if (saved === 'dark') {
    document.documentElement.setAttribute('data-theme', 'dark');
    const knob = document.querySelector('.theme-toggle .knob');
    if (knob) knob.textContent = '🌙';
  }
})();

/* ===== MOBILE MENU ===== */
function toggleMobileMenu() {
  document.getElementById('mobileMenu').classList.toggle('open');
}
function closeMobileMenu() {
  document.getElementById('mobileMenu').classList.remove('open');
}

/* ===== SCROLL LISTENERS ===== */
window.addEventListener('scroll', () => {
  const scrollTop = window.scrollY;
  const docHeight = document.documentElement.scrollHeight - window.innerHeight;

  // Progress bar
  const progress = docHeight > 0 ? (scrollTop / docHeight) * 100 : 0;
  document.getElementById('progressBar').style.width = progress + '%';

  // Back to top button
  const backTop = document.getElementById('backTop');
  backTop.classList.toggle('visible', scrollTop > 400);

  // Navbar shadow
  const nav = document.getElementById('navbar');
  nav.style.boxShadow = scrollTop > 10 ? '0 4px 30px rgba(0,0,0,0.08)' : 'none';
});

/* ===== SCROLL-TRIGGERED ANIMATIONS (Intersection Observer) ===== */
const observerOpts = { threshold: 0.12, rootMargin: '0px 0px -40px 0px' };

const fadeObserver = new IntersectionObserver((entries) => {
  entries.forEach(entry => {
    if (entry.isIntersecting) entry.target.classList.add('visible');
  });
}, observerOpts);

document.querySelectorAll('.fade-in, .fade-in-left, .fade-in-right, .stagger')
  .forEach(el => fadeObserver.observe(el));

/* ===== ANIMATED COUNTERS ===== */
function animateCounter(el, target, duration = 1500) {
  let start = 0;
  const step = target / (duration / 16);
  const update = () => {
    start = Math.min(start + step, target);
    el.textContent = Math.floor(start) + (el.dataset.suffix || '');
    if (start < target) requestAnimationFrame(update);
  };
  requestAnimationFrame(update);
}

const counterObserver = new IntersectionObserver((entries) => {
  entries.forEach(entry => {
    if (entry.isIntersecting) {
      const nums = entry.target.querySelectorAll('.hero-stat .num');
      const targets = [7, 4, 5, 1];
      nums.forEach((num, i) => {
        num.dataset.suffix = num.textContent.includes('+') ? '+' : '';
        animateCounter(num, targets[i]);
      });
      counterObserver.unobserve(entry.target);
    }
  });
}, { threshold: 0.5 });

const statsEl = document.querySelector('.hero-stats');
if (statsEl) counterObserver.observe(statsEl);

/* ===== PARALLAX HERO BLOBS ===== */
window.addEventListener('scroll', () => {
  const scrollY = window.scrollY;
  document.querySelectorAll('.hero-blob').forEach((blob, i) => {
    blob.style.transform = `translateY(${scrollY * (0.1 + i * 0.05)}px)`;
  });
});

/* ===== CARD TILT EFFECT ===== */
document.querySelectorAll('.contrib-card, .future-card, .tech-card').forEach(card => {
  card.addEventListener('mousemove', e => {
    const rect = card.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;
    const cx = rect.width / 2;
    const cy = rect.height / 2;
    const rotX = ((y - cy) / cy) * 4;
    const rotY = ((cx - x) / cx) * 4;
    card.style.transform = `perspective(600px) rotateX(${rotX}deg) rotateY(${rotY}deg) translateY(-6px)`;
  });
  card.addEventListener('mouseleave', () => {
    card.style.transform = '';
  });
});

/* ===== GALLERY LIGHTBOX DATA ===== */
const galleryData = [
  {
    tag: 'UI Screen · Product Discovery',
    title: 'Pinterest-Style <span class="italic">Discovery</span>',
    desc: 'The heart of Priyaraa — a stunning masonry product grid powered by AI recommendations. Buyers browse an infinite, visual-first feed of handmade products with smart category filters, real-time search, and personalized surfacing.',
    features: [
      { icon: '📌', title: 'Masonry Grid Layout', text: 'Pinterest-inspired column layout with varying card heights — keeping the feed visually dynamic and endlessly scrollable.' },
      { icon: '🤖', title: 'AI-Powered Recommendations', text: 'Products are ranked and surfaced based on buyer preferences, past views, and occasion context from SONA conversations.' },
      { icon: '🔍', title: 'Smart Filters & Search', text: 'Category pills, price range, artisan location, and material filters help buyers narrow down to exactly what they need.' },
      { icon: '❤️', title: 'Wishlist & One-tap Save', text: 'One-tap save to wishlist with an animated heart — synced across devices via JWT-authenticated sessions.' }
    ]
  },
  {
    tag: 'AI Feature · SONA Gift Assistant',
    title: 'SONA — <span class="italic">AI Gift Chat</span>',
    desc: "SONA (Smart Occasion & Nature Assistant) is Priyaraa's conversational AI, powered by Azure AI Language. It understands occasion, relationship, emotion, and budget — then recommends the perfect handmade gift.",
    features: [
      { icon: '🧠', title: 'Azure AI Language NLP', text: 'Natural language understanding processes free-text buyer inputs — extracting occasion, budget, recipient traits, and sentiment.' },
      { icon: '💬', title: 'Warm Conversational Flow', text: 'Human-like chat interface with typing indicators, smooth message animations, and contextual follow-up questions.' },
      { icon: '🎁', title: 'Smart Gift Shortlist', text: 'SONA generates a curated list of 3–5 handmade items matching the buyer\'s stated preferences and artisan ratings.' },
      { icon: '✨', title: 'Emotional Personalization', text: 'Goes beyond keywords — understands emotional tone (romantic, heartfelt, fun) to match gifts with the right feeling.' }
    ]
  },
  {
    tag: 'Feature · Buyer-Seller Messaging',
    title: 'Real-time <span class="italic">Chat</span>',
    desc: 'Direct messaging between buyers and artisans brings a human dimension to online shopping. Discuss colors, sizes, delivery timelines, and customization details — all in one place, in real time.',
    features: [
      { icon: '💬', title: 'Multi-thread Inbox', text: 'Organized inbox with all active artisan conversations, unread badges, and thread previews — nothing gets lost.' },
      { icon: '📎', title: 'Media Sharing', text: 'Share reference images, color swatches, and inspiration photos directly in the chat — making customization crystal clear.' },
      { icon: '🔔', title: 'Real-time Notifications', text: 'Instant notifications when artisans respond — keeping buyers engaged and orders moving forward smoothly.' },
      { icon: '✅', title: 'Order Status Updates', text: 'Artisans can share order milestones (started, crafting, dispatched) directly inside the chat thread.' }
    ]
  },
  {
    tag: 'UI Screen · Artisan Profile',
    title: '<span class="italic">Artisan</span> Profile',
    desc: 'Every artisan on Priyaraa gets a beautiful, story-driven profile page. Buyers explore their craft journey, portfolio, ratings, and place customized orders — all on one premium screen.',
    features: [
      { icon: '🧵', title: 'Story & Identity', text: "Name, location, craft speciality, and a personal bio that tells the artisan's story — building trust and emotional connection." },
      { icon: '📸', title: 'Portfolio Masonry Grid', text: "Product photos displayed in a Pinterest-style grid — showcasing the artisan's best work with a consistent aesthetic." },
      { icon: '⭐', title: 'Verified Ratings', text: 'Buyer reviews, satisfaction rate, and verified badges help new buyers make confident, informed purchase decisions.' },
      { icon: '👥', title: 'Follow & Community', text: 'Buyers can follow artisans and get notified of new products, reels, and limited-edition releases.' }
    ]
  },
  {
    tag: 'Infrastructure · Cloud Monitoring',
    title: 'Cloud <span class="italic">Dashboard</span>',
    desc: "A unified monitoring view for Priyaraa's multi-cloud infrastructure — AWS S3, Lambda, Azure App Service, and Azure AI Language. Real-time health, usage metrics, and performance charts in one place.",
    features: [
      { icon: '☁️', title: 'AWS S3 Storage Metrics', text: 'Track stored media volume, bandwidth usage, CDN hit rate, and storage cost optimization across all product image buckets.' },
      { icon: '⚡', title: 'Lambda Invocations', text: 'Monitor serverless function execution counts, cold start times, error rates, and per-function cost breakdowns.' },
      { icon: '🔵', title: 'Azure App Service Health', text: 'Real-time uptime monitoring, response time graphs, memory/CPU charts, and auto-scaling event logs.' },
      { icon: '📊', title: 'Unified Cost View', text: 'Combined AWS + Azure spend dashboard with alerts for budget thresholds — keeping cloud costs permanently optimized.' }
    ]
  },
  {
    tag: 'Responsive Design · Mobile UI',
    title: 'Mobile <span class="italic">Preview</span>',
    desc: "Priyaraa is fully responsive and optimized for mobile browsing. The mobile UI preserves the premium aesthetic — masonry grid, SONA chat, artisan profiles — in a perfectly thumb-friendly layout.",
    features: [
      { icon: '📱', title: 'Touch-Optimized Layout', text: 'Cards are sized for thumbs, tap targets are large, and swipe gestures enable natural, intuitive navigation throughout.' },
      { icon: '🏠', title: 'Bottom Navigation Bar', text: 'Persistent bottom nav (Home, Discover, SONA, Chat, Profile) keeps core actions always accessible.' },
      { icon: '⚡', title: 'Performance-First Build', text: 'Lazy-loaded images, optimized bundles, and caching ensure fast load times even on slower mobile connections.' },
      { icon: '🎨', title: 'Consistent Design Language', text: 'Same warm palette, rounded cards, and typography — every pixel of the desktop design translates beautifully to mobile.' }
    ]
  }
];

let currentLbIndex = 0;

function openLightbox(index) {
  currentLbIndex = index;
  renderLightbox(index);
  document.getElementById('lightboxOverlay').classList.add('open');
  document.body.style.overflow = 'hidden';
}

function renderLightbox(index) {
  const d = galleryData[index];
  document.getElementById('lbTag').textContent = d.tag;
  document.getElementById('lbTitle').innerHTML = d.title;
  document.getElementById('lbDesc').textContent = d.desc;
  document.getElementById('lbCounter').textContent = `${index + 1} of ${galleryData.length}`;
  document.getElementById('lbFeatures').innerHTML = d.features.map(f =>
    `<div class="lb-feature">
      <div class="lbf-icon">${f.icon}</div>
      <div class="lbf-text"><strong>${f.title}</strong>${f.text}</div>
    </div>`
  ).join('');

  // Clone the matching mock screen into the lightbox
  const screens = document.querySelectorAll('.gallery-card .card-mockup .mock-wrap');
  const container = document.getElementById('lbScreenContainer');
  if (screens[index]) {
    container.innerHTML = '';
    container.appendChild(screens[index].cloneNode(true));
  }
}

function closeLightbox() {
  document.getElementById('lightboxOverlay').classList.remove('open');
  document.body.style.overflow = '';
}

function closeLightboxOutside(e) {
  if (e.target === document.getElementById('lightboxOverlay')) closeLightbox();
}

function navigateLightbox(dir) {
  currentLbIndex = (currentLbIndex + dir + galleryData.length) % galleryData.length;
  const box = document.getElementById('lightboxBox');
  box.style.transition = 'transform 0.18s ease, opacity 0.18s ease';
  box.style.transform = `scale(0.97) translateX(${dir * 22}px)`;
  box.style.opacity = '0.6';
  setTimeout(() => {
    renderLightbox(currentLbIndex);
    box.style.transform = 'scale(1) translateX(0)';
    box.style.opacity = '1';
  }, 180);
}

// Keyboard navigation for lightbox
document.addEventListener('keydown', (e) => {
  if (!document.getElementById('lightboxOverlay').classList.contains('open')) return;
  if (e.key === 'Escape') closeLightbox();
  if (e.key === 'ArrowRight') navigateLightbox(1);
  if (e.key === 'ArrowLeft') navigateLightbox(-1);
});
