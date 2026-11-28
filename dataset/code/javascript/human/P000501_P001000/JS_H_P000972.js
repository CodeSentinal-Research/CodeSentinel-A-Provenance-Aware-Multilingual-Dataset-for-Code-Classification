/* ===========================================================
   NIMCET Prep 2027 — Chapter test: Probability & Statistics
   100 original pattern-based questions covering every topic
   the official syllabus lists for this unit.
   =========================================================== */
(function () {
    const App = window.NIMCET;
    const Q = (topic, q, a, c, why) => ({ section: 'math', topic, q, a, c, why });

    App.registerChapterTest({
        section: 'math',
        unit: 'probstat',
        durationMin: 100,
        blurb: 'Counting-based probability, conditional probability and descriptive statistics across 100 questions — a unit that shares all its machinery with Set Theory and Counting.',
        questions: [
            Q('Probability & Statistics', 'Two fair coins are tossed. P(exactly one head) is:', ['1/2', '1/4', '3/4', '1/3'], 0,
                'HT and TH out of four equally likely outcomes.'),

            Q('Probability & Statistics', 'A die is thrown once. The probability of getting a prime number is:', ['1/2', '1/3', '2/3', '1/6'], 0,
                'Primes on a die are 2, 3 and 5 — that is 3 favourable cases out of 6.'),

            Q('Probability & Statistics', 'Three fair coins are tossed together. The probability of getting at least two heads is:', ['1/2', '3/8', '7/8', '1/4'], 0,
                'Favourable outcomes HHH, HHT, HTH, THH give 4 out of 8.'),

            Q('Probability & Statistics', 'A die is thrown twice. The probability that the sum of the numbers is 8 is:', ['5/36', '1/6', '1/9', '5/18'], 0,
                'Sum 8 arises from (2,6), (3,5), (4,4), (5,3), (6,2) — 5 of the 36 outcomes.'),

            Q('Probability & Statistics', 'A number is selected at random from the first 20 natural numbers. The probability that it is a multiple of 4 is:', ['1/4', '1/5', '3/10', '1/2'], 0,
                'Multiples of 4 up to 20 are 4, 8, 12, 16, 20, i.e. 5 out of 20.'),

            Q('Probability & Statistics', 'One card is drawn from a well-shuffled pack of 52 cards. The probability that it is a king is:', ['1/13', '1/52', '4/13', '1/26'], 0,
                'There are 4 kings, so the probability is 4/52 = 1/13.'),

            Q('Probability & Statistics', 'A bag contains 5 red and 3 green balls. One ball is drawn at random. P(green) is:', ['3/8', '5/8', '3/5', '1/3'], 0,
                'Favourable cases 3 out of a total of 8 balls.'),

            Q('Probability & Statistics', 'The number of elements in the sample space when a coin is tossed three times is:', ['8', '6', '3', '9'], 0,
                'Each toss has 2 outcomes, so 2³ = 8 sample points.'),

            Q('Probability & Statistics', 'Two dice are thrown simultaneously. The probability of getting a doublet is:', ['1/6', '1/3', '1/12', '5/36'], 0,
                'The 6 doublets (1,1) … (6,6) out of 36 outcomes give 6/36 = 1/6.'),

            Q('Probability & Statistics', 'A die is thrown twice. The probability that the sum of the numbers is at least 10 is:', ['1/6', '1/12', '5/36', '1/9'], 0,
                'Sums 10, 11, 12 occur in 3 + 2 + 1 = 6 ways out of 36.'),

            Q('Probability & Statistics', 'If P(A) = 0.4, then the probability of the complementary event is:', ['0.6', '0.4', '1.4', '0.5'], 0,
                'P(A\u2032) = 1 − P(A) = 1 − 0.4 = 0.6.'),

            Q('Probability & Statistics', 'A number is chosen at random from 1 to 100. The probability that it is a perfect square is:', ['1/10', '1/5', '9/100', '1/20'], 0,
                'The perfect squares 1², 2², …, 10² give 10 favourable numbers out of 100.'),

            Q('Probability & Statistics', 'If P(A) = 1/2, P(B) = 1/3 and P(A ∩ B) = 1/4, then P(A ∪ B) equals:', ['7/12', '5/12', '11/12', '1/12'], 0,
                'Addition theorem: 1/2 + 1/3 − 1/4 = (6 + 4 − 3)/12 = 7/12.'),

            Q('Probability & Statistics', 'A and B are mutually exclusive events with P(A) = 0.3 and P(B) = 0.45. Then P(A ∪ B) is:', ['0.75', '0.135', '0.15', '0.6'], 0,
                'For mutually exclusive events P(A ∩ B) = 0, so P(A ∪ B) = 0.3 + 0.45.'),

            Q('Probability & Statistics', 'One card is drawn from a pack of 52 cards. The probability that it is a king or a heart is:', ['4/13', '17/52', '1/13', '15/52'], 0,
                '4/52 + 13/52 − 1/52 = 16/52 = 4/13, the king of hearts being counted once.'),

            Q('Probability & Statistics', 'A number is chosen at random from 1 to 30. The probability that it is divisible by 2 or by 3 is:', ['2/3', '1/2', '5/6', '7/15'], 0,
                '15 + 10 − 5 = 20 favourable numbers, so 20/30 = 2/3.'),

            Q('Probability & Statistics', 'If P(A) = 0.6, P(B) = 0.3 and P(A ∪ B) = 0.7, then P(A ∩ B) is:', ['0.2', '0.1', '0.3', '0.4'], 0,
                'P(A ∩ B) = P(A) + P(B) − P(A ∪ B) = 0.6 + 0.3 − 0.7.'),

            Q('Probability & Statistics', 'Two dice are thrown. The probability that the sum is 7 or 11 is:', ['2/9', '1/6', '5/36', '1/3'], 0,
                'The two events are mutually exclusive: 6/36 + 2/36 = 8/36 = 2/9.'),

            Q('Probability & Statistics', 'If P(A) = 0.5, P(B) = 0.4 and P(A ∩ B) = 0.2, the probability that exactly one of A, B occurs is:', ['0.5', '0.7', '0.3', '0.9'], 0,
                'P(A) + P(B) − 2P(A ∩ B) = 0.5 + 0.4 − 0.4 = 0.5.'),

            Q('Probability & Statistics', 'If A and B are mutually exclusive and exhaustive events with P(A) = 2/5, then P(B) equals:', ['3/5', '2/5', '1', '0'], 0,
                'Exhaustive and mutually exclusive means P(A) + P(B) = 1.'),

            Q('Probability & Statistics', 'If P(A) = 0.25, P(B) = 0.50 and P(A ∩ B) = 0.14, then P(neither A nor B) is:', ['0.39', '0.61', '0.36', '0.75'], 0,
                'P(A\u2032 ∩ B\u2032) = 1 − P(A ∪ B) = 1 − (0.25 + 0.50 − 0.14) = 0.39.'),

            Q('Probability & Statistics', 'The probability that a student passes in Mathematics is 0.7, in English 0.6 and in both 0.45. The probability that he passes in at least one subject is:', ['0.85', '0.75', '0.95', '0.55'], 0,
                '0.7 + 0.6 − 0.45 = 0.85 by the addition theorem.'),

            Q('Probability & Statistics', 'If A and B are independent with P(A) = 1/3 and P(B) = 1/4, then P(A ∩ B) is:', ['1/12', '7/12', '1/7', '1/2'], 0,
                'For independent events P(A ∩ B) = P(A)·P(B).'),

            Q('Probability & Statistics', 'A and B are independent events with P(A) = 0.3 and P(B) = 0.6. Then P(A ∪ B) is:', ['0.72', '0.90', '0.18', '0.66'], 0,
                'P(A ∩ B) = 0.18, so P(A ∪ B) = 0.3 + 0.6 − 0.18 = 0.72.'),

            Q('Probability & Statistics', 'Two cards are drawn one by one with replacement from a pack of 52 cards. The probability that both are aces is:', ['1/169', '1/221', '1/2652', '2/13'], 0,
                'With replacement the draws are independent: (4/52)² = (1/13)².'),

            Q('Probability & Statistics', 'Two cards are drawn one after another without replacement. The probability that both are kings is:', ['1/221', '1/169', '1/13', '1/26'], 0,
                '(4/52) × (3/51) = 12/2652 = 1/221.'),

            Q('Probability & Statistics', 'A speaks the truth in 75% of cases and B in 80% of cases. The percentage of cases in which they contradict each other is:', ['35%', '30%', '25%', '65%'], 0,
                'They contradict when one is truthful and the other is not: 0.75×0.2 + 0.25×0.8 = 0.35.'),

            Q('Probability & Statistics', 'The probabilities that A and B hit a target are 1/3 and 1/5. If both fire once, the probability that the target is hit is:', ['7/15', '8/15', '1/15', '2/5'], 0,
                'P(hit) = 1 − P(both miss) = 1 − (2/3)(4/5) = 1 − 8/15.'),

            Q('Probability & Statistics', 'A bag contains 4 white and 5 black balls. Two balls are drawn one by one without replacement. The probability that both are black is:', ['5/18', '25/81', '5/9', '2/9'], 0,
                '(5/9) × (4/8) = 20/72 = 5/18.'),

            Q('Probability & Statistics', 'The probabilities that A and B solve a problem independently are 1/2 and 1/3. The probability that the problem is solved is:', ['2/3', '1/6', '5/6', '1/3'], 0,
                '1 − (1/2)(2/3) = 1 − 1/3 = 2/3.'),

            Q('Probability & Statistics', 'If A and B are independent with P(A) = 0.4 and P(B) = 0.5, then the probability that neither occurs is:', ['0.3', '0.2', '0.1', '0.7'], 0,
                'P(A\u2032)·P(B\u2032) = 0.6 × 0.5 = 0.3, since complements of independent events are independent.'),

            Q('Probability & Statistics', 'Three men fire at a target independently with probabilities 1/6, 1/4 and 1/3 of hitting. The probability that the target is NOT hit is:', ['5/12', '7/12', '1/72', '1/3'], 0,
                '(5/6)(3/4)(2/3) = 30/72 = 5/12.'),

            Q('Probability & Statistics', 'A die is thrown. Given that the number obtained is even, the probability that it is 4 is:', ['1/3', '1/6', '1/2', '2/3'], 0,
                'The reduced sample space {2, 4, 6} has 3 equally likely points.'),

            Q('Probability & Statistics', 'Two dice are thrown. Given that the sum is 7, the probability that one of the dice shows 2 is:', ['1/3', '1/6', '2/9', '1/2'], 0,
                'Sum 7 has 6 outcomes, of which (2,5) and (5,2) contain a 2.'),

            Q('Probability & Statistics', 'If P(A) = 0.6 and P(A ∩ B) = 0.3, then P(B | A) equals:', ['0.5', '0.3', '0.18', '2'], 0,
                'P(B | A) = P(A ∩ B)/P(A) = 0.3/0.6.'),

            Q('Probability & Statistics', 'A family has two children. Given that at least one of them is a boy, the probability that both are boys is:', ['1/3', '1/2', '1/4', '2/3'], 0,
                'The reduced sample space is {BB, BG, GB} and only BB is favourable.'),

            Q('Probability & Statistics', 'A card drawn from a pack is found to be a face card. The probability that it is a king is:', ['1/3', '1/13', '4/13', '1/4'], 0,
                'There are 12 face cards of which 4 are kings.'),

            Q('Probability & Statistics', 'Two dice are thrown. Given that the sum is even, the probability that the sum is 8 is:', ['5/18', '5/36', '1/6', '1/4'], 0,
                'Even sums occur in 18 outcomes; sum 8 occurs in 5 of them.'),

            Q('Probability & Statistics', 'If P(B) = 0.5 and P(A | B) = 0.4, then P(A ∩ B) equals:', ['0.2', '0.8', '0.9', '0.1'], 0,
                'Multiplication theorem: P(A ∩ B) = P(B)·P(A | B) = 0.5 × 0.4.'),

            Q('Probability & Statistics', 'Three coins are tossed. Given that at least one head appears, the probability that all three are heads is:', ['1/7', '1/8', '1/3', '1/4'], 0,
                'The conditioning event has 7 outcomes and only HHH is favourable.'),

            Q('Probability & Statistics', 'Bag I contains 3 red and 4 black balls; Bag II contains 5 red and 6 black balls. A bag is chosen at random and a red ball is drawn. The probability that it came from Bag I is:', ['33/68', '35/68', '3/7', '5/11'], 0,
                "By Bayes' theorem the answer is (3/7) ÷ (3/7 + 5/11) = (33/77) ÷ (68/77) = 33/68."),

            Q('Probability & Statistics', 'Urn A has 2 white and 3 black balls, urn B has 4 white and 1 black ball. An urn is chosen at random and a white ball is drawn. The probability that urn A was chosen is:', ['1/3', '2/3', '1/5', '2/5'], 0,
                'Posterior = (2/5) ÷ (2/5 + 4/5) = 2/6 = 1/3.'),

            Q('Probability & Statistics', 'Machines A and B produce 60% and 40% of the items of a factory; 2% of A\u2019s output and 3% of B\u2019s output are defective. An item picked at random is defective. The probability that it was made by A is:', ['1/2', '3/5', '2/5', '1/4'], 0,
                '0.6×0.02 = 0.012 and 0.4×0.03 = 0.012, so the posterior is 0.012/0.024 = 1/2.'),

            Q('Probability & Statistics', 'Of two coins one is fair and the other is two-headed. A coin is chosen at random and tossed, showing a head. The probability that it is the two-headed coin is:', ['2/3', '1/2', '1/3', '3/4'], 0,
                'Posterior = (1/2 × 1) ÷ (1/2 × 1 + 1/2 × 1/2) = (1/2) ÷ (3/4) = 2/3.'),

            Q('Probability & Statistics', 'In a class 60% are boys and 40% are girls. 5% of the boys and 10% of the girls opted for a special course. A student who opted is selected. The probability that the student is a girl is:', ['4/7', '3/7', '2/5', '1/2'], 0,
                '0.04 ÷ (0.03 + 0.04) = 4/7.'),

            Q('Probability & Statistics', 'Three identical boxes contain respectively (1 white, 2 black), (2 white, 1 black) and (3 white, 1 black) balls. A box is chosen at random and a white ball is drawn. The probability that it came from the third box is:', ['3/7', '4/7', '1/3', '3/4'], 0,
                'Likelihoods are 1/3, 2/3, 3/4 with equal priors, so the posterior is (3/4) ÷ (1/3 + 2/3 + 3/4) = (3/4) ÷ (7/4).'),

            Q('Probability & Statistics', 'Four cards are drawn from a well-shuffled pack of 52 cards. The probability that all are diamonds is:', ['11/4165', '13/4165', '11/2380', '1/4165'], 0,
                '<sup>13</sup>C<sub>4</sub> / <sup>52</sup>C<sub>4</sub> = 715/270725 = 11/4165.'),

            Q('Probability & Statistics', 'A committee of 3 is chosen at random from 5 men and 4 women. The probability that it consists only of men is:', ['5/42', '5/21', '1/21', '1/6'], 0,
                '<sup>5</sup>C<sub>3</sub> / <sup>9</sup>C<sub>3</sub> = 10/84 = 5/42.'),

            Q('Probability & Statistics', 'A committee of 3 is chosen at random from 5 men and 4 women. The probability that it has exactly 2 women is:', ['5/14', '3/14', '5/42', '2/7'], 0,
                '(<sup>4</sup>C<sub>2</sub> × <sup>5</sup>C<sub>1</sub>) / <sup>9</sup>C<sub>3</sub> = 30/84 = 5/14.'),

            Q('Probability & Statistics', 'A bag contains 6 red and 4 blue balls. Three balls are drawn at random. The probability that all are red is:', ['1/6', '1/5', '1/2', '3/10'], 0,
                '<sup>6</sup>C<sub>3</sub> / <sup>10</sup>C<sub>3</sub> = 20/120 = 1/6.'),

            Q('Probability & Statistics', 'From a bag of 6 red and 4 blue balls, three balls are drawn at random. The probability that exactly two are red is:', ['1/2', '3/10', '2/5', '1/6'], 0,
                '(<sup>6</sup>C<sub>2</sub> × <sup>4</sup>C<sub>1</sub>) / <sup>10</sup>C<sub>3</sub> = 60/120 = 1/2.'),

            Q('Probability & Statistics', 'Three boys and two girls are seated in a row at random. The probability that the two girls occupy the two end seats is:', ['1/10', '1/5', '2/5', '1/20'], 0,
                '(2! × 3!) / 5! = 12/120 = 1/10.'),

            Q('Probability & Statistics', 'Five persons are seated in a row at random. The probability that two particular persons sit together is:', ['2/5', '1/5', '3/5', '1/2'], 0,
                'Treating the pair as one block: (2! × 4!) / 5! = 48/120 = 2/5.'),

            Q('Probability & Statistics', 'The letters of the word LEVEL are arranged at random. The probability that the arrangement begins and ends with L is:', ['1/10', '1/5', '1/15', '2/15'], 0,
                'Total arrangements = 5!/(2!2!) = 30; fixing both L\u2019s leaves 3!/2! = 3 arrangements.'),

            Q('Probability & Statistics', 'A four-digit number is formed using the digits 1, 2, 3, 4 without repetition. The probability that it is divisible by 4 is:', ['1/4', '1/3', '1/6', '1/2'], 0,
                'The last two digits must be 12, 24 or 32; each allows 2! arrangements, giving 6 of the 24 numbers.'),

            Q('Probability & Statistics', 'Two distinct numbers are chosen at random from 1 to 10. The probability that their sum is odd is:', ['5/9', '4/9', '1/2', '5/18'], 0,
                'One odd and one even number: (5 × 5) / <sup>10</sup>C<sub>2</sub> = 25/45 = 5/9.'),

            Q('Probability & Statistics', 'From 7 men and 6 women, 5 persons are selected at random. The probability of selecting 3 men and 2 women is:', ['175/429', '35/429', '175/1287', '25/143'], 0,
                '(<sup>7</sup>C<sub>3</sub> × <sup>6</sup>C<sub>2</sub>) / <sup>13</sup>C<sub>5</sub> = 525/1287 = 175/429.'),

            Q('Probability & Statistics', 'Six boys and four girls stand in a row at random. The probability that all the girls stand together is:', ['1/30', '1/21', '1/6', '2/15'], 0,
                '(7! × 4!) / 10! = 120960/3628800 = 1/30.'),

            Q('Probability & Statistics', 'A committee of 4 is formed at random from 6 boys and 4 girls. The probability that it contains at least one girl is:', ['13/14', '1/14', '3/14', '11/14'], 0,
                '1 − <sup>6</sup>C<sub>4</sub>/<sup>10</sup>C<sub>4</sub> = 1 − 15/210 = 13/14.'),

            Q('Probability & Statistics', 'A box has 4 white and 5 red balls. Three balls are drawn at random. The probability that all three are of the same colour is:', ['1/6', '5/42', '1/12', '3/14'], 0,
                '(<sup>4</sup>C<sub>3</sub> + <sup>5</sup>C<sub>3</sub>) / <sup>9</sup>C<sub>3</sub> = 14/84 = 1/6.'),

            Q('Probability & Statistics', 'Two cards are drawn at random from a pack of 52 cards. The probability of getting one king and one queen is:', ['8/663', '16/663', '4/663', '2/221'], 0,
                '(4 × 4) / <sup>52</sup>C<sub>2</sub> = 16/1326 = 8/663.'),

            Q('Probability & Statistics', 'If the odds in favour of an event are 3 : 5, the probability of the event is:', ['3/8', '5/8', '3/5', '5/3'], 0,
                'Odds a : b in favour give probability a/(a + b).'),

            Q('Probability & Statistics', 'If the probability of an event is 2/7, the odds against it are:', ['5 : 2', '2 : 5', '2 : 7', '7 : 2'], 0,
                'Failures : successes = 5 : 2 since P(not E) = 5/7.'),

            Q('Probability & Statistics', 'If the odds against an event are 4 : 3, the probability that the event occurs is:', ['3/7', '4/7', '3/4', '4/3'], 0,
                'Odds against a : b give probability b/(a + b) = 3/7.'),

            Q('Probability & Statistics', 'Two dice are thrown. The odds in favour of getting a doublet are:', ['1 : 5', '5 : 1', '1 : 6', '6 : 1'], 0,
                '6 favourable and 30 unfavourable outcomes reduce to 1 : 5.'),

            Q('Probability & Statistics', 'A fair coin is tossed 6 times. The probability of getting exactly 4 heads is:', ['15/64', '3/32', '5/16', '1/2'], 0,
                '<sup>6</sup>C<sub>4</sub>(1/2)<sup>6</sup> = 15/64.'),

            Q('Probability & Statistics', 'A die is thrown 5 times. The probability of getting exactly two sixes is:', ['625/3888', '125/3888', '25/216', '3125/7776'], 0,
                '<sup>5</sup>C<sub>2</sub>(1/6)²(5/6)³ = 1250/7776 = 625/3888.'),

            Q('Probability & Statistics', 'For a binomial distribution with n = 10 and p = 1/5, the mean and variance are respectively:', ['2 and 1.6', '2 and 8', '1.6 and 2', '5 and 4'], 0,
                'Mean = np = 2 and variance = npq = 10 × 0.2 × 0.8 = 1.6.'),

            Q('Probability & Statistics', 'If the mean and variance of a binomial distribution are 4 and 2, then n equals:', ['8', '6', '4', '16'], 0,
                'npq/np = q = 1/2, so p = 1/2 and n = 4 ÷ (1/2) = 8.'),

            Q('Probability & Statistics', 'A fair coin is tossed 4 times. The probability of getting at least one head is:', ['15/16', '1/16', '1/2', '7/8'], 0,
                '1 − P(no head) = 1 − (1/2)<sup>4</sup> = 15/16.'),

            Q('Probability & Statistics', 'The probability that a marksman hits a target is 1/4. If he fires 3 shots, the probability of exactly one hit is:', ['27/64', '9/64', '27/256', '1/4'], 0,
                '<sup>3</sup>C<sub>1</sub>(1/4)(3/4)² = 27/64.'),

            Q('Probability & Statistics', 'The arithmetic mean of 2, 4, 6, 8 and 10 is:', ['6', '5', '7', '8'], 0,
                'Sum 30 divided by 5 observations gives 6.'),

            Q('Probability & Statistics', 'The median of the data 3, 7, 5, 9, 11, 13 is:', ['8', '7', '9', '10'], 0,
                'Arranged: 3, 5, 7, 9, 11, 13; the median is (7 + 9)/2 = 8.'),

            Q('Probability & Statistics', 'The mode of the data 2, 3, 4, 3, 5, 3, 6, 4 is:', ['3', '4', '2', '5'], 0,
                'The value 3 occurs three times, more than any other.'),

            Q('Probability & Statistics', 'The mean of the first 10 natural numbers is:', ['5.5', '5', '6', '55'], 0,
                'Sum = 55 and n = 10, so the mean is 5.5.'),

            Q('Probability & Statistics', 'The mean of 5 observations is 12. If one observation equal to 20 is removed, the mean of the remaining observations is:', ['10', '11', '8', '12'], 0,
                'Remaining sum = 60 − 20 = 40 over 4 observations.'),

            Q('Probability & Statistics', 'For a moderately skewed distribution the mean is 20 and the median is 22. The mode is:', ['26', '24', '18', '21'], 0,
                'Empirical relation: Mode = 3 Median − 2 Mean = 66 − 40 = 26.'),

            Q('Probability & Statistics', 'The mean of 20 observations is 15. If each observation is multiplied by 2, the new mean is:', ['30', '15', '17', '45'], 0,
                'Multiplying every observation by k multiplies the mean by k.'),

            Q('Probability & Statistics', 'The mean of 10 numbers is 12. If 5 is added to each number, the new mean is:', ['17', '12', '60', '7'], 0,
                'Adding a constant c to every observation increases the mean by c.'),

            Q('Probability & Statistics', 'The median of 4, 6, 8, 10, 12, 14, 16 is:', ['10', '8', '12', '9'], 0,
                'With 7 observations the median is the 4th value.'),

            Q('Probability & Statistics', 'For the frequency distribution x = 1, 2, 3, 4 with f = 4, 3, 2, 1, the mean is:', ['2', '2.5', '3', '1.5'], 0,
                'Σfx = 4 + 6 + 6 + 4 = 20 and Σf = 10, so the mean is 2.'),

            Q('Probability & Statistics', 'The mean of 40 students of section A is 30 and that of 60 students of section B is 40. The combined mean is:', ['36', '35', '34', '38'], 0,
                '(40×30 + 60×40)/100 = 3600/100 = 36.'),

            Q('Probability & Statistics', 'In a moderately skewed distribution the mean is 24.6 and the mode is 26.1. The median is:', ['25.1', '25.4', '24.1', '26.4'], 0,
                'Mode = 3 Median − 2 Mean gives 26.1 = 3M − 49.2, so M = 25.1.'),

            Q('Probability & Statistics', 'The mean of 6 numbers is 8. If the number 12 in the data is replaced by 18, the new mean is:', ['9', '8.5', '10', '9.5'], 0,
                'New sum = 48 − 12 + 18 = 54, so the mean is 54/6 = 9.'),

            Q('Probability & Statistics', 'For the distribution x = 1, 2, 3, 4, 5 with f = 2, 4, 6, 3, 5, the median is:', ['3', '2.5', '4', '3.5'], 0,
                'N = 20 and cumulative frequencies 2, 6, 12, 15, 20 place both the 10th and 11th observations at x = 3.'),

            Q('Probability & Statistics', 'The mean of the first five multiples of 3 is:', ['9', '7.5', '12', '6'], 0,
                '(3 + 6 + 9 + 12 + 15)/5 = 45/5 = 9.'),

            Q('Probability & Statistics', 'The class mark (mid-value) of the class interval 25–35 is:', ['30', '25', '35', '10'], 0,
                'Class mark = (lower limit + upper limit)/2.'),

            Q('Probability & Statistics', 'For the classes 0–10, 10–20, 20–30, 30–40 with frequencies 5, 8, 12, 5, the modal class is:', ['20–30', '10–20', '30–40', '0–10'], 0,
                'The modal class is the class with the highest frequency, here 12.'),

            Q('Probability & Statistics', 'The class size of the classes 5–15, 15–25, 25–35, … is:', ['10', '5', '15', '20'], 0,
                'Class size = upper limit − lower limit = 15 − 5 = 10.'),

            Q('Probability & Statistics', 'The frequencies of four classes are 3, 7, 10 and 5. The cumulative frequency of the third class is:', ['20', '10', '17', '25'], 0,
                '3 + 7 + 10 = 20.'),

            Q('Probability & Statistics', 'The range of the data 12, 25, 8, 30, 15 is:', ['22', '30', '18', '25'], 0,
                'Range = maximum − minimum = 30 − 8.'),

            Q('Probability & Statistics', 'The variance of the first five natural numbers is:', ['2', '√2', '2.5', '5'], 0,
                'Mean = 3 and Σ(x − x̄)² = 10, so the variance is 10/5 = 2.'),

            Q('Probability & Statistics', 'The standard deviation of 2, 4, 6, 8, 10 is:', ['2√2', '8', '4', '2'], 0,
                'Mean = 6, Σ(x − x̄)² = 40, variance = 8 and σ = 2√2.'),

            Q('Probability & Statistics', 'If each observation of a data set is increased by 5, then the standard deviation:', ['remains unchanged', 'increases by 5', 'increases by 25', 'becomes 5 times'], 0,
                'A shift of origin does not change the deviations from the mean.'),

            Q('Probability & Statistics', 'If each observation of a data set is multiplied by 3, the variance becomes:', ['9 times the original', '3 times the original', 'unchanged', '6 times the original'], 0,
                'Variance is scaled by the square of the multiplier.'),

            Q('Probability & Statistics', 'For a distribution with mean 40 and standard deviation 8, the coefficient of variation is:', ['20%', '32%', '5%', '500%'], 0,
                'C.V. = (σ/x̄) × 100 = (8/40) × 100.'),

            Q('Probability & Statistics', 'The mean deviation about the mean for the data 3, 6, 9, 12, 15 is:', ['3.6', '4.2', '3', '4'], 0,
                'Mean = 9 and Σ|x − x̄| = 6 + 3 + 0 + 3 + 6 = 18, so M.D. = 18/5.'),

            Q('Probability & Statistics', 'For 5 observations, Σx = 20 and Σx² = 100. The variance is:', ['4', '2', '20', '16'], 0,
                'Variance = Σx²/n − (Σx/n)² = 20 − 16 = 4.'),

            Q('Probability & Statistics', 'The variance of the first 10 natural numbers is:', ['8.25', '7.5', '9', '8.5'], 0,
                'Variance of first n natural numbers = (n² − 1)/12 = 99/12 = 8.25.'),

            Q('Probability & Statistics', 'The standard deviation of 10 observations is 4. If each observation is multiplied by 2 and then increased by 3, the new standard deviation is:', ['8', '11', '4', '16'], 0,
                'Scaling multiplies σ by 2 while adding a constant leaves it unchanged.')
        ]
    });
})();
