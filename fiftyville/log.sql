-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT *
  FROM crime_scene_reports
 WHERE street LIKE '%Humphrey%' AND year = 2021 AND month = 7 AND day = 28; -- find the reports (parameters: date, street)

SELECT *
  FROM crime_scene_reports
 WHERE street LIKE '%Humphrey%' AND year = 2021 AND month = 7 AND day = 28 AND description LIKE "%duck%"; -- find the report (parameters: date, street, keyword "duck")