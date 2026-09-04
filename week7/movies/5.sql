-- 5. Titles and years of all Harry Potter movies, in chronological order (title beginning with "Harry Potter and the ...")
SELECT title, movies.year FROM movies WHERE title LIKE 'Harry Potter %' ORDER BY year;
