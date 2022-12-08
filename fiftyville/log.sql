-- Keep a log of any SQL queries you execute as you solve the mystery.


-- FOUND crime time: 10:15
-- FOUND flight date: 29 July 2021
-- FOUND flight origin: fiftyville


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

-- FOUND crime time 10:15

SELECT transcript -- Find interview transcripts
  FROM interviews
 WHERE transcript LIKE ("%bakery%")
       AND year = 2021
       AND month = 7
       AND day = 28;
-- FOUND flight date: 29 July 2021
-- FOUND flight origin: fiftyville

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

SELECT * -- Take a look at ATM transavtions (year, month, day, atm_location)
  FROM atm_transactions
 WHERE year = 2021
       AND month = 7
       AND day = 28
       AND atm_location = "Leggett Street";

SELECT * -- Take a look at ATM transavtions (year, month, day, atm_location, transaction_type)
  FROM atm_transactions
 WHERE year = 2021
       AND month = 7
       AND day = 28
       AND atm_location = "Leggett Street"
       AND transaction_type = "withdraw";

SELECT * -- Take a look at phone_calls (year, month, day, duration)
  FROM phone_calls
 WHERE year = 2021
       AND month = 7
       AND day = 28
       AND duration < 60;

SELECT * -- check for flights (year, month, day, origin airport)
  FROM flights
 WHERE year = 2021
      AND month = 7
      AND day = 29
      AND origin_airport_id IN
           (SELECT id
              FROM airports
             WHERE city = "Fiftyville")
             ORDER BY hour
             LIMIT 1;
-- FOUND flight id: 36
-- FOUND destination id: 4
