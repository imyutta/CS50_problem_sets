-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * -- find the reports (parameters: date, street)
  FROM crime_scene_reports
 WHERE street LIKE '%Humphrey%'
       AND year = 2021
       AND month = 7
       AND day = 28;

SELECT * -- find the report (parameters: date, street, keyword "duck:)
  FROM crime_scene_reports
 WHERE street LIKE '%Humphrey%'
       AND year = 2021
       AND month = 7
       AND day = 28
       AND description LIKE "%duck%"; -