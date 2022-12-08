-- Keep a log of any SQL queries you execute as you solve the mystery.


-- FOUND crime time: 10:15
-- FOUND flight date: 29 July 2021
-- FOUND flight origin: fiftyville
-- FOUND destination city: New York City


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
-- FOUND licence plates


SELECT * -- Take a look at ATM transavtions (year, month, day, atm_location)
  FROM atm_transactions
 WHERE year = 2021
       AND month = 7
       AND day = 28
       AND atm_location = "Leggett Street";
--FOUND amount of money withdrown from the ATM
--FOUND account_numberS

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
-- FOUND telephone numbers

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

SELECT city -- find destination city
  FROM airports
 WHERE id IN
        (SELECT destination_airport_id
           FROM flights
          WHERE year = 2021
                AND month = 7
                AND day = 29
                AND origin_airport_id IN
                    (SELECT id
                       FROM airports
                      WHERE city = "Fiftyville")
                      ORDER BY hour
                      LIMIT 1);
-- FOUND destination city: New York City

SELECT name -- take a look at people data (parameters: phone number, license plate)
  FROM people -- first table for intersection: phone numbers
 WHERE phone_number IN
      (SELECT caller
        FROM phone_calls
       WHERE year = 2021
         AND month = 7
         AND day = 28
         AND duration < 60)

    INTERSECT

SELECT name -- second table for intersection: license_plates
  FROM people
 WHERE license_plate IN
      (SELECT license_plate
        FROM bakery_security_logs
       WHERE year = 2021
         AND month = 7
         AND day = 28
         AND hour = 10
         AND minute >= 15
         AND minute <= 25)

INTERSECT

SELECT name
  FROM people
 WHERE passport_number IN
       (SELECT passport_number
          FROM passengers
         WHERE flight_id IN
              (SELECT id
                 FROM flights
                WHERE year = 2021
                       AND month = 7
                       AND day = 29
                       AND origin_airport_id IN
                           (SELECT id
                              FROM airports
                             WHERE city = "Fiftyville")
                             ORDER BY hour
                             LIMIT 1));

                 