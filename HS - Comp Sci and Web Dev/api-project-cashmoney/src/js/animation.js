const navButton = document.querySelector(".nav-button");
const navOpen = document.querySelector(".nav-open");

//const tween = TweenLite.to(object, time, {animate})

/*const tween = TweenLite.to('cover', 1, {
    width: "60%"
})*/

const tl = new TimelineLite({ paused: true, reversed: true });

tl.to(
  "nav",
  1,
  {
    width: "100%",
    ease: Power2.easeOut,
  },
  "-=.5"
).fromTo(
  ".nav-open",
  0.5,
  {
    opacity: 1,
    x: -50,
    ease: Power2.easeOut,
  },
  {
    opacity: 1,
    x: 0,
    onComplete: function () {
      navOpen.style.pointerEvents = "auto";
      console.log("done");
    },
  }
);
navButton.addEventListener("click", (e) => {
  console.log("clicked");
  if (tl.isActive()) {
    console.log("active");
    //e.preventDefault();
    e.stopImmediatePropagation();
    return false;
  }
  toggleTween(tl);
});

function toggleTween(tween) {
  tween.reverse() ? tween.play : tween.reverse();
}
