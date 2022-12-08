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
       AND description LIKE "%duck%";
-- time of the crime 10:15 am

SELECT transcript -- Find interview transcripts
  FROM interviews
 WHERE transcript LIKE ("%bakery%")
       AND year = 2021
       AND month = 7
       AND day = 28;

SELECT * -- take a look at bakery security logs (year, month,day)
  FROM bakery_security_logs
 WHERE year = 2021
       AND month = 7
       AND day = 28;


SELECT * -- take a CLOTHER look at bakery security logs (year, month,day, hour, minute, activity)
  FROM bakery_security_logs
 WHERE year = 2021
       AND month = 7
       AND day = 28
       AND hour = 10
       AND minute >= 15
       AND minute <= 25;

-- found some license_plates

SELECT * -- Take a look at ATM transavtions (year, month, day, atm_location)
  FROM atm_transactions
 WHERE year = 2021
       AND month = 7
       AND day = 28
       AND atm_location = "Leggett Street";