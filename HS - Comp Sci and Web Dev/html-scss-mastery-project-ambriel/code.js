window.onscroll = function () {
  stickyNavbar();
};
window.onresize = resize;

let navbar = document.getElementById("header");
let sec2 = document.getElementById("home");
let sticky = navbar.offsetTop;
let viewportWidth = window.innerWidth || document.documentElement.clientWidth;

function resize() {
  viewportWidth = window.innerWidth || document.documentElement.clientWidth;
}

function stickyNavbar() {
  if (window.pageYOffset >= sticky && viewportWidth >= 769) {
    navbar.classList.add("sticky");
    sec2.style.marginTop = "60px";
  } else {
    navbar.classList.remove("sticky");
    sec2.style.marginTop = "0";
  }
}

let close = document.getElementById("menu-close");
let open = document.getElementById("menu-open");
let header = document.getElementById("header");
let link1 = document.getElementsByClassName("navbar-link")[0];
let link2 = document.getElementsByClassName("navbar-link")[1];
let link3 = document.getElementsByClassName("navbar-link")[2];
let link4 = document.getElementsByClassName("navbar-link")[3];
let link5 = document.getElementsByClassName("navbar-link")[4];

open.onclick = function () {
  open.style.display = "none";
  header.style.display = "block";
  close.style.display = "block";
};

close.onclick = function () {
  close.style.display = "none";
  header.style.display = "none";
  open.style.display = "block";
};

link1.onclick = function () {
  hideMenu();
};
link2.onclick = function () {
  hideMenu();
};
link3.onclick = function () {
  hideMenu();
};
link4.onclick = function () {
  hideMenu();
};
link5.onclick = function () {
  hideMenu();
};

function hideMenu() {
  if (viewportWidth <= 769) {
    close.style.display = "none";
    header.style.display = "none";
    open.style.display = "block";
    console.log("hello");
  }
}

let resizeTimer;
window.addEventListener("resize", () => {
  document.body.classList.add("resize-animation-stopper");
  clearTimeout(resizeTimer);
  resizeTimer = setTimeout(() => {
    document.body.classList.remove("resize-animation-stopper");
  }, 400);
});

let loc1 = document.getElementById("cities-loc-1");
let loc2 = document.getElementById("cities-loc-2");
let loc3 = document.getElementById("cities-loc-3");
let loc4 = document.getElementById("cities-loc-4");
let title = document.getElementById("cities-box-title");
let picture = document.getElementById("cities-box-image");
let text = document.getElementById("cities-box-text");

loc1.onclick = function () {
  title.innerHTML = "Milan";
  picture.src = "img/locmilan.jpg";
  text.innerHTML =
    "Besides being capital of fashion and design, it is also home to the national stock exchange with its high-end restaurants and shops. In addition, the famous Leonardo da Vinci's painting ''The Last Supper'' is located here.";
};

loc2.onclick = function () {
  title.innerHTML = "Pisa";
  picture.src = "img/locpisa.jpg";
  text.innerHTML =
    "Located in Italy's Tuscany region it is most famously known for its Leaning Tower of Pisa, a tower of white marble built on soft ground that causes it to tilt over. Right next to it is the Cattedrale di Pisa, and together they attract over 5 million visitors each year.";
};

loc3.onclick = function () {
  title.innerHTML = "Rome";
  picture.src = "img/locrome.jpg";
  text.innerHTML =
    "The capital of Italy, Rome is also called the Eternal City for its ancient structures from the Trevi Fountain (pictured above) to the great Colosseum. Fun fact: an estimated amount of 3,000 euros are thrown into the Trevi Fountain every day";
};

loc4.onclick = function () {
  title.innerHTML = "Pompei";
  picture.src = "img/locpompei.jpg";
  text.innerHTML =
    "The famous eruption of Mount Vesuvius in the year 79 A.D. buried the city of Pompei in volcanic ashe. Many people died and the city was abandoned, but the ashe preserved much of the daily aspects of life that we can learn much from.";
};
