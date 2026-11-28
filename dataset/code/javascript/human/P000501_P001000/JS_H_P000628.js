let data = getPortfolioData();
const $ = id => document.getElementById(id);
const PIN_KEY = "portfolio-admin-unlocked-v1";

$("loginBtn").onclick = login;
$("pinInput").addEventListener("keydown",e=>{if(e.key==="Enter")login()});
$("lockBtn").onclick=()=>{localStorage.removeItem(PIN_KEY);location.reload()};
$("resetBtn").onclick=()=>{if(confirm("Reset all portfolio content to the original demo data?")){localStorage.removeItem(PORTFOLIO_KEY);location.reload()}};

function login(){
  if($("pinInput").value==="2026"){
    localStorage.setItem(PIN_KEY,"yes");
    showAdmin();
  }else alert("Incorrect PIN. Local demo PIN: 2026");
}

if(localStorage.getItem(PIN_KEY)==="yes") showAdmin();

function showAdmin(){
  $("loginView").classList.add("hidden");
  $("adminView").classList.remove("hidden");
  renderTab("overview");
}

$("adminNav").addEventListener("click",e=>{
  const b=e.target.closest("button[data-tab]"); if(!b)return;
  document.querySelectorAll("#adminNav button").forEach(x=>x.classList.remove("active"));
  b.classList.add("active"); renderTab(b.dataset.tab);
});

function save(){
  savePortfolioData(data);
  $("savedMessage").textContent="Saved ✓";
  setTimeout(()=>$("savedMessage").textContent="",1800);
}

function renderTab(tab){
  const titles={overview:"Overview",profile:"Profile",skills:"Skills",projects:"Projects",events:"Hackathons & Events",achievements:"Achievements",coding:"Coding Profiles"};
  $("tabTitle").textContent=titles[tab];
  const root=$("adminContent");
  if(tab==="overview") root.innerHTML=overview();
  if(tab==="profile") root.innerHTML=profileForm();
  if(tab==="skills") root.innerHTML=collection("skills","Skill");
  if(tab==="projects") root.innerHTML=collection("projects","Project");
  if(tab==="events") root.innerHTML=collection("events","Hackathon / Event");
  if(tab==="achievements") root.innerHTML=collection("achievements","Achievement");
  if(tab==="coding") root.innerHTML=codingForm();
  bindTab(tab);
}

function overview(){
  return `<div class="grid grid-2">${[
    ["Projects",data.projects.length,"projects"],["Skills",data.skills.length,"skills"],
    ["Hackathons & Events",data.events.length,"events"],["Achievements",data.achievements.length,"achievements"]
  ].map(x=>`<button class="card card-body overview-card" data-jump="${x[2]}"><span class="muted">${x[0]}</span><strong>${x[1]}</strong><span class="small muted">Manage →</span></button>`).join("")}</div>
  <div class="card card-body" style="margin-top:18px"><h3>Your workflow</h3><p class="muted">Add a project → upload its image → add GitHub/live link → save. Then open the portfolio to see the update.</p></div>`;
}

function profileForm(){
  const p=data.profile;
  return `<div class="form wide">
    ${field("name","Name",p.name)}${field("headline","Headline",p.headline)}${field("hero","Hero text",p.hero)}
    <label>About<textarea class="textarea" data-field="about">${esc(p.about)}</textarea></label>
    ${field("email","Email",p.email)}${field("github","GitHub URL",p.github)}${field("linkedin","LinkedIn URL",p.linkedin)}
    ${field("leetcode","LeetCode URL",p.leetcode)}${field("codechef","CodeChef URL",p.codechef)}${field("resume","Resume URL",p.resume)}
    ${field("availability","Availability",p.availability)}
    <button class="btn btn-primary" id="saveProfile">Save Profile</button>
  </div>`;
}

function codingForm(){
  const c=data.coding;
  return `<div class="form wide">${field("leetcodeSolved","LeetCode problems solved",c.leetcodeSolved,"number")}${field("leetcodeRating","LeetCode rating",c.leetcodeRating)}
  ${field("codechefSolved","CodeChef problems solved",c.codechefSolved,"number")}${field("codechefRating","CodeChef rating",c.codechefRating)}
  <button class="btn btn-primary" id="saveCoding">Save Coding Profiles</button></div>`;
}

function collection(type,label){
  const items=data[type];
  const list=items.map((x,i)=>`
    <div class="list-item space"><div><strong>${esc(x.title||x.name)}</strong><div class="small muted">${esc(x.category||x.type||x.status||"")}</div></div>
    <div class="row"><button class="btn edit-item" data-type="${type}" data-index="${i}">Edit</button><button class="btn danger delete-item" data-type="${type}" data-index="${i}">Delete</button></div></div>`).join("");
  return `<div class="admin-grid"><div class="list">${list || `<div class="list-item muted">No ${label.toLowerCase()} entries yet.</div>`}</div>
    <div class="form"><h3>Add ${label}</h3>${editor(type,null)}<button class="btn btn-primary" id="addItem" data-type="${type}">Add</button></div></div>`;
}

function editor(type,item){
  const x=item||{};
  if(type==="skills") return `${field("name","Skill name",x.name)}${field("category","Category",x.category)}${select("level","Level",x.level||"Learning",["Learning","Familiar","Intermediate","Strong"])}`;
  if(type==="projects") return `${field("title","Project title",x.title)}<label>Description<textarea class="textarea" data-f="description">${esc(x.description)}</textarea></label>${field("technologies","Technologies (comma separated)",(x.technologies||[]).join(", "))}${select("status","Status",x.status||"In Progress",["Completed","In Progress","Planned"])}${field("github","GitHub URL",x.github)}${field("live","Live Demo URL",x.live)}${imageUpload("image",x.image)}`;
  if(type==="events") return `${field("name","Event name",x.name)}${field("type","Type",x.type||"Hackathon")}${field("date","Date",x.date)}<label>Description<textarea class="textarea" data-f="description">${esc(x.description)}</textarea></label>${field("result","Result (optional)",x.result)}`;
  return `${field("title","Achievement title",x.title)}<label>Description<textarea class="textarea" data-f="description">${esc(x.description)}</textarea></label>${field("date","Date",x.date)}`;
}

function field(name,label,value="",type="text"){return `<label>${label}<input class="input" data-f="${name}" type="${type}" value="${esc(value)}"></label>`}
function select(name,label,value,opts){return `<label>${label}<select class="select" data-f="${name}">${opts.map(o=>`<option ${o===value?"selected":""}>${o}</option>`).join("")}</select></label>`}
function imageUpload(name,value){return `<label>Project image<input class="input" id="imageFile" type="file" accept="image/*"></label>${value?`<img class="upload-preview" src="${value}" alt="Current project image">`:""}`}

function bindTab(tab){
  document.querySelectorAll("[data-jump]").forEach(b=>b.onclick=()=>renderTab(b.dataset.jump));
  if(tab==="profile") $("saveProfile").onclick=()=>{
    document.querySelectorAll("[data-field]").forEach(el=>data.profile[el.dataset.field]=el.value);
    save();
  };
  if(tab==="coding") $("saveCoding").onclick=()=>{
    data.coding.leetcodeSolved=Number(document.querySelector('[data-f="leetcodeSolved"]').value||0);
    data.coding.leetcodeRating=document.querySelector('[data-f="leetcodeRating"]').value;
    data.coding.codechefSolved=Number(document.querySelector('[data-f="codechefSolved"]').value||0);
    data.coding.codechefRating=document.querySelector('[data-f="codechefRating"]').value;
    save();
  };
  document.querySelectorAll(".delete-item").forEach(b=>b.onclick=()=>{
    const t=b.dataset.type,i=Number(b.dataset.index);
    if(confirm("Delete this item?")){data[t].splice(i,1);save();renderTab(tab)}
  });
  document.querySelectorAll(".edit-item").forEach(b=>b.onclick=()=>editItem(b.dataset.type,Number(b.dataset.index),tab));
  const add=$("addItem"); if(add) add.onclick=()=>addItem(add.dataset.type,tab);
}

function readEditor(type){
  const q=s=>document.querySelector(`[data-f="${s}"]`);
  const base={id:makeId(type)};
  if(type==="skills") return {...base,name:q("name").value,category:q("category").value,level:q("level").value};
  if(type==="projects") return {...base,title:q("title").value,description:q("description").value,technologies:q("technologies").value.split(",").map(x=>x.trim()).filter(Boolean),status:q("status").value,github:q("github").value,live:q("live").value,image:window.currentUpload||"" ,featured:true};
  if(type==="events") return {...base,name:q("name").value,type:q("type").value,date:q("date").value,description:q("description").value,result:q("result").value};
  return {...base,title:q("title").value,description:q("description").value,date:q("date").value};
}

function addItem(type,tab){
  window.currentUpload="";
  const file=$("imageFile");
  if(file && file.files[0]) {
    const reader=new FileReader();
    reader.onload=()=>{window.currentUpload=reader.result; data[type].push(readEditor(type)); save(); renderTab(tab);};
    reader.readAsDataURL(file.files[0]);
  } else { data[type].push(readEditor(type)); save(); renderTab(tab); }
}

function editItem(type,index,tab){
  const existing=data[type][index];
  const root=$("adminContent");
  root.innerHTML=`<div class="form wide"><h3>Edit</h3>${editor(type,existing)}<div class="row"><button class="btn btn-primary" id="updateItem">Update</button><button class="btn" id="cancelEdit">Cancel</button></div></div>`;
  window.currentUpload=existing.image||"";
  const file=$("imageFile");
  if(file) file.onchange=()=>{const r=new FileReader();r.onload=()=>window.currentUpload=r.result;r.readAsDataURL(file.files[0])};
  $("updateItem").onclick=()=>{
    const updated=readEditor(type);
    updated.id=existing.id;
    if(type==="projects") updated.image=window.currentUpload;
    data[type][index]=updated;save();renderTab(tab);
  };
  $("cancelEdit").onclick=()=>renderTab(tab);
}

function esc(v){return String(v??"").replace(/[&<>"']/g,c=>({"&":"&amp;","<":"&lt;",">":"&gt;",'"':"&quot;","'":"&#039;"}[c]));}