# Airgead Banking
Airgead Banking Investment Calculator

# Scenario

You are asked to collaborate with Airgead Banking, one of Chada Tech’s clients. Airgead Banking is well known in the community. They often sponsor schools and have recently decided to partner with the local high school to develop a program that will teach students the concepts of fiscal responsibility (such as living within their means and spending less than they make) via an interactive system. The initial focus for this project will be on investing and the power of compound interest. You will develop an application that allows users to see how their investments will grow over time.

# Pseudocode

1.	Display data input screen with blank fields for:
 
 a.	Initial investment amount
   
    i.	Cin initial investment

  b.	Monthly deposit
   
    i.	Cin monthly deposit

  c.	Annual interest
   
    i.	Cin annual interest

  d.	Number of years
    
    i.	Cin number of years
    ii.	Convert number of years into months (year months)
 
  e.	A way to submit the data

2.	Cout balance and interest without additional deposits
 
  a.	For i < year months
    
    i.	Interest = opening amount * ((interest rate / 100) / 12)
    ii.	Interest so far += interest
    iii.	Closing balance = opening balance + interest
    iv.	If i % 12 == 11
      1.	Cout year number << closing balance (year end balance) << interest so far (year end interest)
      2.	++ year
      3.	Interest so far = 0
    v.	Opening balance = closing balance

3.	Cout balance and interest with user imputed monthly deposit
 
 a.	For i < year months
   
    i.	Interest = (opening amount + monthly deposit) * ((interest rate / 100) / 12)
    ii.	Interest so far += interest
    iii.	Closing balance = opening balance + interest
    iv.	If i % 12 == 11
      1.	Cout year number << closing balance (year end balance) << interest so far (year end interest)
      2.	++ year
      3.	Interest so far = 0

  	 v.	Opening balance = closing balance

