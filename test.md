# TestCase 1 : properly sort the cutting lengths from most -> least valuable when given in mixed order
## Input:
- Rod Length: 22 
- Cutting Lengths: (5, 3), (11, 10), (1, 1)

## Output: 
- Cuts made: 22 @ 1 = 22
- Remainder: 0
- Total Value: 21


# TestCase 2 : avoids cutting rod to a negative length when given too long of an input
## Input:
- Rod Length: 12 
- Cutting Lengths: (15, 11)

## Output: 
- Cuts Made: 
- 0 @ 0 = 0.0
- Remainder: 12
- Total Value: 0


# TestCase 3 : cant cut perfectly
## Input:
- Rod Length: 21
- Cutting Lengths: (11, 30), (3, 6), (2, 2)

## Output:
- Cuts Made: 
- 21 @ 1 = 0
- Remainder: 0
- Total Value: 30