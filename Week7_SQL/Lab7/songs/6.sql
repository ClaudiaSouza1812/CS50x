SELECT name FROM songs WHERE artist_id =
(SELECT id FROM artists WHERE name LIKE "post malone");