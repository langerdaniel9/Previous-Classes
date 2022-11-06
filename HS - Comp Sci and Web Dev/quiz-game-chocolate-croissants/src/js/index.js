import { questions, mainButton, exitButton, divs, inputs } from "./_variables";

let numCorrect = 0;
let questionNumber = 0;

function insertQuestionValues(qNum) {
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

function changeHTMLandGoToNextQuestion() {
  insertQuestionValues(questionNumber);
  questionNumber += 1;
}

function changeHTMLandFinishQuiz(numberQuestions) {
  const top60 = document.getElementById("choices");
  const title = document.getElementById("main-title");
  top60.style.opacity = "0";
  title.innerText = "You finished the Quiz";
  question.innerText = `You got ${numCorrect}/${numberQuestions}`;
  mainButton.innerHTML = "Retake";
}

exitButton.onclick = function () {
  location.reload();
};

function changeMainButtonToNext() {
  const top80 = document.getElementById("top80");
  mainButton.innerHTML = "Next";
  top80.style.opacity = "1";
  inputs.forEach((input) => (input.checked = false));
}

function changeMainButtonToGradeQuiz() {
  mainButton.innerHTML = "Grade Quiz";
}

function checkIfRight(num) {
  inputs.forEach((choice) => {
    if (choice.checked == true) {
      choice.checked = false;
      if (choice.value == questions[num].correct) {
        numCorrect++;
      }
    }
  });
}

mainButton.addEventListener("click", function () {
  const numberQuestions = questions.length;
  if (questionNumber == 0) {
    changeMainButtonToNext();
    changeHTMLandGoToNextQuestion();
  } else if (questionNumber < numberQuestions - 1) {
    checkIfRight(questionNumber - 1);
    changeHTMLandGoToNextQuestion();
  } else if (questionNumber == numberQuestions - 1) {
    checkIfRight(questionNumber - 1);
    changeHTMLandGoToNextQuestion();
    changeMainButtonToGradeQuiz();
  } else if (questionNumber == numberQuestions) {
    checkIfRight(questionNumber - 1);
    questionNumber += 1;
    changeHTMLandFinishQuiz(numberQuestions);
  } else {
    location.reload();
  }
});

function findNumberOfSelf(self, selfArray) {
  for (let i = 0; i < selfArray.length; i++) {
    if (self === selfArray[i]) {
      return i;
    }
  }
}

divs.forEach((choice) =>
  choice.addEventListener("click", function () {
    let whichChecked = findNumberOfSelf(choice, divs);
    inputs[whichChecked].checked = true;
  })
);
