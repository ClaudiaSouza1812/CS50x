-- Keep a log of any SQL queries you execute as you solve the mystery.
-- query with the date and local for read the description report:
SELECT description,
FROM crime_scene_reports
WHERE month = 07 AND day = 28 AND year = 2021 AND street LIKE "Humphrey Street";
--OK

--description
-------------
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted
--today with three witnesses who were present at the time – each of their interview transcripts mentions
--the bakery. Littering took place at 16:36. No known witnesses.

-- query to select PEOPLE THAT MENTIONS BAKERY in their interviews AFTER or ON the day theft:
SELECT id, name, transcript, day, month, year
FROM interviews
WHERE transcript LIKE "%bakery%" AND month >= 7 AND day >= 28 AND year >= 2021;
--OK

--name                                                                                                                                                                                                                                                                                                     |
---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage
--from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- query to select ALL LICENSE PLATES THAT LEFT THE BAKERY WITHIN THE THEFT HOUR and its activity:
SELECT bs.license_plate, bs.activity FROM bakery_security_logs AS bs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit";
--OK

+---------------+----------+
| license_plate | activity |
+---------------+----------+
| 5P2BI95       | exit     |
| 94KL13X       | exit     |
| 6P58WS2       | exit     |
| 4328GD8       | exit     |
| G412CB7       | exit     |
| L93JTIZ       | exit     |
| 322W7JE       | exit     |
| 0NTHK55       | exit     |
+---------------+----------+

-- quety to select ALL DATA FROM ALL PEOPLE THAT HAS ITS LICENSE PLATE in the bakery parking within the time of the thefth:
SELECT id, name, phone_number, passport_number, license_plate FROM people
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit");
--OK

+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
| 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+---------+----------------+-----------------+---------------+

--Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the
--ATM on Leggett Street and saw the thief there withdrawing some money.

-- query to select ALL PEOPLE THAT WAS ON ATM at the correct address after or before being in the bakery on that day and time frame:
SELECT p.id, name, phone_number, passport_number, license_plate, bc.account_number, tm.atm_location, tm.transaction_type, tm.amount, tm.year, tm.month, tm.day FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
WHERE p.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit")
AND tm.transaction_type LIKE "%withdra%" AND tm.year = 2021 AND tm.month = 7 AND tm.day = 28 AND tm.atm_location LIKE "Leggett Street";
--ok

+--------+-------+----------------+-----------------+---------------+----------------+----------------+------------------+--------+------+-------+-----+
|   id   | name  |  phone_number  | passport_number | license_plate | account_number |  atm_location  | transaction_type | amount | year | month | day |
+--------+-------+----------------+-----------------+---------------+----------------+----------------+------------------+--------+------+-------+-----+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | Leggett Street | withdraw         | 50     | 2021 | 7     | 28  |
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | Leggett Street | withdraw         | 35     | 2021 | 7     | 28  |
| 396669 | Iman  | (829) 555-5269 | 7049073643      | L93JTIZ       | 25506511       | Leggett Street | withdraw         | 20     | 2021 | 7     | 28  |
| 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | Leggett Street | withdraw         | 48     | 2021 | 7     | 28  |
+--------+-------+----------------+-----------------+---------------+----------------+----------------+------------------+--------+------+-------+-----+


--Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they
--were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- query to select CALL CALLERS on that day and time:
--ok
SELECT p.id, p.name, p.phone_number, p.passport_number, p.license_plate, bc.account_number, pc.caller, pc.duration, pc.id, pc.receiver, pc.year, pc.month, pc.day FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
WHERE p.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit")
AND tm.transaction_type LIKE "%withdra%" AND tm.year = 2021 AND tm.month = 7 AND tm.day = 28 AND tm.atm_location LIKE "Leggett Street" AND pc.duration <= 60;

+--------+-------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
|   id   | name  |  phone_number  | passport_number | license_plate | account_number |     caller     | duration | id  |    receiver    | year | month | day |
+--------+-------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 28  |
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
+--------+-------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+

-- query to select CALL RECEIVERS FROM CALL CALLERS on that day and time:
--ok
SELECT p.id, p.name, p.phone_number, p.passport_number, p.license_plate, bc.account_number, pc.caller, pc.duration, pc.id, pc.receiver, pc.year, pc.month, pc.day FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
JOIN phone_calls AS pc ON p.phone_number = pc.receiver
WHERE pc.duration <= 60 AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND p.phone_number IN (SELECT pc.receiver FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
WHERE p.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit")
AND tm.transaction_type LIKE "%withdra%" AND tm.year = 2021 AND tm.month = 7 AND tm.day = 28 AND tm.atm_location LIKE "Leggett Street" AND pc.duration <= 60);

+--------+-----------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
|   id   |   name    |  phone_number  | passport_number | license_plate | account_number |     caller     | duration | id  |    receiver    | year | month | day |
+--------+-----------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 27  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 29  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 29  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 30  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 30  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 31  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 31  |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 8     | 1   |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 8     | 1   |
| 847116 | Philip    | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 8     | 1   |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 26  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 27  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 29  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 30  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 30  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 30  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 31  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 31  |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 8     | 1   |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 8     | 1   |
| 864400 | Robin     | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 8     | 1   |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 27  |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 27  |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 29  |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 30  |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 31  |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 7     | 31  |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 8     | 1   |
| 639344 | Charlotte | (455) 555-5315 | 7226911797      | Z5FH038       | 15871517       | (367) 555-5533 | 31       | 395 | (455) 555-5315 | 2021 | 8     | 1   |
+--------+-----------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
-- without Charlotte
+--------+--------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
|   id   |  name  |  phone_number  | passport_number | license_plate | account_number |     caller     | duration | id  |    receiver    | year | month | day |
+--------+--------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       | 47746428       | (770) 555-1861 | 49       | 255 | (725) 555-3243 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
| 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       | 94751264       | (367) 555-5533 | 45       | 233 | (375) 555-8161 | 2021 | 7     | 28  |
+--------+--------+----------------+-----------------+---------------+----------------+----------------+----------+-----+----------------+------+-------+-----+

--Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they
--were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- query to select PASSENGERS, FLIGHTS and AIRPORTS related to CALLERS
--ok
SELECT p.name, p.phone_number, pa.flight_id, pa.seat, pa.passport_number, fl.origin_airport_id, fl.destination_airport_id, ai.abbreviation, ai.full_name, ai.city, fl.year, fl.month, fl.day, fl.hour, fl.minute FROM passengers AS pa
JOIN people AS p ON pa.passport_number = p.passport_number
JOIN flights AS fl ON pa.flight_id = fl.id
JOIN airports AS ai ON fl.destination_airport_id = ai.id
WHERE pa.passport_number IN
(SELECT p.passport_number FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
WHERE p.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit")
AND tm.transaction_type LIKE "%withdra%" AND tm.year = 2021 AND tm.month = 7 AND tm.day = 28 AND tm.atm_location LIKE "Leggett Street" AND pc.duration <= 60);

+-------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------------+---------------+------+-------+-----+------+--------+
| name  | flight_id | seat | passport_number | origin_airport_id | destination_airport_id | abbreviation |                full_name                |     city      | year | month | day | hour | minute |
+-------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------------+---------------+------+-------+-----+------+--------+
| Diana | 18        | 4C   | 3592750733      | 8                 | 6                      | BOS          | Logan International Airport             | Boston        | 2021 | 7     | 29  | 16   | 0      |
| Diana | 24        | 2C   | 3592750733      | 7                 | 8                      | CSF          | Fiftyville Regional Airport             | Fiftyville    | 2021 | 7     | 30  | 16   | 27     |
| Bruce | 36        | 4A   | 5773159633      | 8                 | 4                      | LGA          | LaGuardia Airport                       | New York City | 2021 | 7     | 29  | 8    | 20     |
| Diana | 54        | 6C   | 3592750733      | 8                 | 5                      | DFS          | Dallas/Fort Worth International Airport | Dallas        | 2021 | 7     | 30  | 10   | 19     |
+-------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------------+---------------+------+-------+-----+------+--------+


-- query to select PASSENGERS, FLIGHTS and AIRPORTS related to RECEIVERS
-- ok
SELECT p.name, p.phone_number, pa.flight_id, pa.seat, pa.passport_number, fl.origin_airport_id, fl.destination_airport_id, ai.abbreviation, ai.full_name, ai.city, fl.year, fl.month, fl.day, fl.hour, fl.minute FROM passengers AS pa
JOIN people AS p ON pa.passport_number = p.passport_number
JOIN flights AS fl ON pa.flight_id = fl.id
JOIN airports AS ai ON fl.destination_airport_id = ai.id
WHERE pa.passport_number IN
(SELECT p.passport_number FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
JOIN phone_calls AS pc ON p.phone_number = pc.receiver
WHERE pc.duration <= 60 AND p.phone_number IN (SELECT pc.receiver FROM people AS p
JOIN bank_accounts AS bc ON p.id = bc.person_id
JOIN atm_transactions AS tm ON bc.account_number = tm.account_number
JOIN phone_calls AS pc ON p.phone_number = pc.caller
WHERE p.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 26 AND activity = "exit")
AND tm.transaction_type LIKE "%withdra%" AND tm.year = 2021 AND tm.month = 7 AND tm.day = 28 AND tm.atm_location LIKE "Leggett Street" AND pc.duration <= 60));

+-----------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------+---------------+------+-------+-----+------+--------+
|   name    | flight_id | seat | passport_number | origin_airport_id | destination_airport_id | abbreviation |             full_name             |     city      | year | month | day | hour | minute |
+-----------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------+---------------+------+-------+-----+------+--------+
| Charlotte | 5         | 8D   | 7226911797      | 8                 | 3                      | LAX          | Los Angeles International Airport | Los Angeles   | 2021 | 7     | 27  | 11   | 45     |
| Philip    | 10        | 2A   | 3391710505      | 8                 | 4                      | LGA          | LaGuardia Airport                 | New York City | 2021 | 7     | 30  | 13   | 55     |
| Charlotte | 26        | 9A   | 7226911797      | 2                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 27  | 13   | 32     |
| Philip    | 28        | 2A   | 3391710505      | 3                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 26  | 22   | 49     |
| Charlotte | 42        | 2B   | 7226911797      | 4                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 30  | 13   | 22     |
| Philip    | 47        | 4D   | 3391710505      | 4                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 30  | 9    | 46     |
+-----------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------+---------------+------+-------+-----+------+--------+


-- compare the results of CALLERS and RECEIVERS that took flights:

+-------+----------------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------------+---------------+------+-------+-----+------+--------+
| name  |  phone_number  | flight_id | seat | passport_number | origin_airport_id | destination_airport_id | abbreviation |                full_name                |     city      | year | month | day | hour | minute |
+-------+----------------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------------+---------------+------+-------+-----+------+--------+
| Diana | (770) 555-1861 | 18        | 4C   | 3592750733      | 8                 | 6                      | BOS          | Logan International Airport             | Boston        | 2021 | 7     | 29  | 16   | 0      |
| Diana | (770) 555-1861 | 24        | 2C   | 3592750733      | 7                 | 8                      | CSF          | Fiftyville Regional Airport             | Fiftyville    | 2021 | 7     | 30  | 16   | 27     |
| Bruce | (367) 555-5533 | 36        | 4A   | 5773159633      | 8                 | 4                      | LGA          | LaGuardia Airport                       | New York City | 2021 | 7     | 29  | 8    | 20     |
| Diana | (770) 555-1861 | 54        | 6C   | 3592750733      | 8                 | 5                      | DFS          | Dallas/Fort Worth International Airport | Dallas        | 2021 | 7     | 30  | 10   | 19     |
+-------+----------------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------------+---------------+------+-------+-----+------+--------+

+-----------+----------------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------+---------------+------+-------+-----+------+--------+
|   name    |  phone_number  | flight_id | seat | passport_number | origin_airport_id | destination_airport_id | abbreviation |             full_name             |     city      | year | month | day | hour | minute |
+-----------+----------------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------+---------------+------+-------+-----+------+--------+
| Charlotte | (455) 555-5315 | 5         | 8D   | 7226911797      | 8                 | 3                      | LAX          | Los Angeles International Airport | Los Angeles   | 2021 | 7     | 27  | 11   | 45     |
| Philip    | (725) 555-3243 | 10        | 2A   | 3391710505      | 8                 | 4                      | LGA          | LaGuardia Airport                 | New York City | 2021 | 7     | 30  | 13   | 55     |
| Charlotte | (455) 555-5315 | 26        | 9A   | 7226911797      | 2                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 27  | 13   | 32     |
| Philip    | (725) 555-3243 | 28        | 2A   | 3391710505      | 3                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 26  | 22   | 49     |
| Charlotte | (455) 555-5315 | 42        | 2B   | 7226911797      | 4                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 30  | 13   | 22     |
| Philip    | (725) 555-3243 | 47        | 4D   | 3391710505      | 4                 | 8                      | CSF          | Fiftyville Regional Airport       | Fiftyville    | 2021 | 7     | 30  | 9    | 46     |
+-----------+----------------+-----------+------+-----------------+-------------------+------------------------+--------------+-----------------------------------+---------------+------+-------+-----+------+--------+

-- If the earlyest flight was at 8:20 and the passenger were Bruce, so, he is the thief and he only has called Robin, so, he is the accomplice, the destiny was New York City :) yup!!!!




























