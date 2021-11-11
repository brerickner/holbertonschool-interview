#!/usr/bin/node

// Script that prints all characters of a Star Wars movie using the Star Wars API 'https://swapi.co/api/films/{movie_id}/'.
// Print one character per line, same order as "characters" list in the /films/{movie_id}/ response.
// Must use request module.
// Using swapi-node wrapper package.

const request = require('request');

const filmId = process.argv[2];
let url = 'https://swapi-api.hbtn.io/api/films/';

url = url + filmId + '/';

request(url, async function (error, response, body) {
  // Printing the error if occurred
  if (error) console.log(error);

  // Printing status code
  // console.log(response.statusCode);

  // Printing characters from body in JSON format
  const Characters = JSON.parse(body).characters;

  // Extract new url for each character to make a new request for their name
  for (const people of Characters) {
    // Promise object either becomes 'resolved' or 'rejected;'
    // (resolve) is called when the asynchronous task completes successfully
    // and returns the results of the task as a value. The second (reject)
    // is called when the task fails, and returns the reason for failure,
    // which is typically an error object.
    await new Promise(function (resolve, reject) {
      request(people, function (error, response, body) {
        if (error) console.log(error);

        // Printing status code
        // console.log(response.statusCode);

        // Printing character name
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
