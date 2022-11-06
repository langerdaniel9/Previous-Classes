import { questions } from "./_questions";

let numCorrect = 0;
let questionNumber = 0;
const mainButton = document.getElementById("main-btn");
const exitButton = document.getElementById("exit-btn");

function insertQuestionVars(qNum) {
  const title = document.getElementById("main-title");
  const question = document.getElementById("question");
  const choice1 = document.getElementById("choice1");
  const choice2 = document.getElementById("choice2");
  const choice3 = document.getElementById("choice3");
  const choice4 = document.getElementById("choice4");
  title.innerText = `Question Number ${qNum + 1}`;
  question.innerText = questions[qNum].question;
  choice1.innerText = questions[qNum].choice1;
  choice2.innerText = questions[qNum].choice2;
  choice3.innerText = questions[qNum].choice3;
  choice4.innerText = questions[qNum].choice4;
}

exitButton.onclick = function () {
  location.reload();
};

function findWhichChoiceIsSelected(num) {
  const c1 = document.getElementsByName("1")[0];
  const c2 = document.getElementsByName("1")[1];
  const c3 = document.getElementsByName("1")[2];
  const c4 = document.getElementsByName("1")[3];
  if (c1.checked == true) {
    c1.checked = false;
    if ("A" == questions[num].correct) {
      numCorrect++;
    }
  } else if (c2.checked == true) {
    c2.checked = false;
    if ("B" == questions[num].correct) {
      numCorrect++;
    }
  } else if (c3.checked == true) {
    c3.checked = false;
    if ("C" == questions[num].correct) {
      numCorrect++;
    }
  } else if (c4.checked == true) {
    c4.checked = false;
    if ("D" == questions[num].correct) {
      numCorrect++;
    }
  }
}

mainButton.addEventListener("click", function () {
  const top80 = document.getElementById("top80");
  const numberQuestions = questions.length;
  if (questionNumber == 0) {
    mainButton.innerHTML = "Next";
    top80.style.opacity = "1";
    insertQuestionVars(questionNumber);
    questionNumber += 1;
  } else if (questionNumber < numberQuestions - 1) {
    findWhichChoiceIsSelected(questionNumber - 1);
    insertQuestionVars(questionNumber);
    questionNumber += 1;
  } else if (questionNumber == numberQuestions - 1) {
    mainButton.innerHTML = "Grade Quiz";
    findWhichChoiceIsSelected(questionNumber - 1);
    insertQuestionVars(questionNumber);
    questionNumber += 1;
  } else if (questionNumber == numberQuestions) {
    const top60 = document.getElementById("choices");
    const title = document.getElementById("main-title");
    mainButton.innerHTML = "Grade Quiz";
    findWhichChoiceIsSelected(questionNumber - 1);
    questionNumber += 1;
    top60.style.opacity = "0";
    title.innerText = "You finished the Quiz";
    question.innerText = `You got ${numCorrect}/${numberQuestions}`;
    mainButton.innerHTML = "Retake";
  } else {
    location.reload();
  }
});
