const books = ["book 1", "book 2", "book 3"];

/*console.log(books);
console.log(books[1]);
console.log(books.length); //return # of items in list
console.log(books[books.length - 1]); //return last
*/

books.push("book 4");
books.unshift("book 0");

const booksReversed = [...books].reverse();
//console.log(books);
//console.log(booksReversed);

const bookIndex = books.findIndex((book) => book === "book 2");
const newBooks = [...books.slice(0, bookIndex), ...books.slice(bookIndex + 1)];

//console.log(newBooks);
