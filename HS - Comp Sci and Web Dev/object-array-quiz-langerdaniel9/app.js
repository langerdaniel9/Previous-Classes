const presidents = [
  { name: "Donald Trump", terms: 1, party: "R" },
  { name: "Barack Obama", terms: 2, party: "D" },
  { name: "George W. Bush", terms: 2, party: "R" },
  { name: "Bill Clinton", terms: 2, party: "D" },
  { name: "George H.W. Bush", terms: 1, party: "R" },
  { name: "Ronald Reagan", terms: 2, party: "R" },
  { name: "Jimmy Carter", terms: 1, party: "D" },
  { name: "Gerlad Ford", terms: 1, party: "R" },
  { name: "Richard Nixon", terms: 2, party: "R" },
  { name: "John F. Kennedy", terms: 1, party: "D" },
  { name: "Lyndon Johnson", terms: 2, party: "D" },
  { name: "Dwight Eisenhower", terms: 2, party: "R" },
];

//Challenge Questions
//1) Filter all presidents, leaving only the Democratic ones

const filteredListOne = [...presidents];
let filteredListOneLength = filteredListOne.length;
let challengeOneAnswer = [];

for (
  filteredListOneIterations = 0;
  filteredListOneIterations < filteredListOneLength;
  filteredListOneIterations++
) {
  if (filteredListOne[filteredListOneIterations].party === "D")
    challengeOneAnswer.push(
      filteredListOne.slice(
        filteredListOneIterations,
        filteredListOneIterations + 1
      )
    );
}
console.log("Challenge 1", challengeOneAnswer.flat());

//2)Filter all presidents to leave only one term Republican presidents HINT use If statement

const filteredListTwo = [...presidents];
let filteredListTwoLength = filteredListTwo.length;
let challengeTwoAnswer = [];

for (
  filteredListTwoIterations = 0;
  filteredListTwoIterations < filteredListTwoLength;
  filteredListTwoIterations++
) {
  if (
    filteredListTwo[filteredListTwoIterations].party === "R" &&
    filteredListTwo[filteredListTwoIterations].terms === 1
  )
    challengeTwoAnswer.push(
      filteredListTwo.slice(
        filteredListTwoIterations,
        filteredListTwoIterations + 1
      )
    );
}
console.log("Challenge 2", challengeTwoAnswer.flat());

//3) return only the last three presidents

const filteredListThree = [...presidents];
let filteredListThreeLength = filteredListThree.length;
let challengeThreeAnswer = [];

challengeThreeAnswer.push(
  filteredListThree[filteredListThreeLength - 3],
  filteredListThree[filteredListThreeLength - 2],
  filteredListThree[filteredListThreeLength - 1]
);

console.log("Challenge 3", challengeThreeAnswer.flat());

//4) log all dems who served 2 terms. HINT use chain filter, filter and slice

const filteredListFour = [...presidents];
let filteredListFourLength = filteredListFour.length;
let challengeFourAnswer = [];

for (
  filteredListFourIterations = 0;
  filteredListFourIterations < filteredListFourLength;
  filteredListFourIterations++
) {
  if (
    filteredListFour[filteredListFourIterations].party === "D" &&
    filteredListFour[filteredListFourIterations].terms === 2
  )
    challengeFourAnswer.push(
      filteredListFour.slice(
        filteredListFourIterations,
        filteredListFourIterations + 1
      )
    );
}
console.log("Challenge 4", challengeFourAnswer.flat());

//BONUS write a script to check if LBJ was a 2 term president. IF he was then alert("LBJ served two terms") else alert "LBJ was one and done"

const filteredListBonus = [...presidents];
let filteredListBonusLength = filteredListBonus.length;

for (
  filteredListBonusIterations = 0;
  filteredListBonusIterations < filteredListBonusLength;
  filteredListBonusIterations++
) {
  if (
    filteredListBonus[filteredListBonusIterations].name === "Lyndon Johnson" &&
    filteredListBonus[filteredListBonusIterations].terms === 2
  ) {
    alert("LBJ served two terms");
    break;
  } else {
    alert("LBJ was one and done");
    break;
  }
}
