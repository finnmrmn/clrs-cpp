# Exercises 1.1

## 1.1-1
I might group items by weight and then stack each group by size, which lets me
ensure the stacks will not easily topple or crush the items towards the bottom.
As for a problem that requires finding the shortest distance between two points,
I might look for the closest available power outlet or toilet when I am out,
since I am looking to walk the least distance.

## 1.1-2
Space, energy, hardware, and development costs. One should also consider whether
the problem needs solving at all, because the best algorithm is meaningless when
it solves a totally irrelevant problem.

## 1.1-3
Arrays are probably the most typical data structure out there. Its strength lies
in how it is contiguous and instantly indexable. However, arrays are slower when
needing to grow in size, since a lot of copying is necessary. To compensate for
this, growing the array by more than one element can be more practical, 
like doubling in size. However, this could be problematic if the elements in the
array are huge. Another strength of arrays is locality, which often makes it 
easier (faster) for the computer to process the data.

## 1.1-4
Both involve finding optimal routes, but they are optimising for different
things. The shortest-path algorithm is searching for the best route to take to
get from A to B. The travelling salesperson problem seeks to find the best route
to deliver goods in a circular route. This means it is about finding the 
shortest path from A to A while visiting the required places, which makes it a 
much heavier problem to solve.

## 1.1-5
A problem where only the best solution will do is entering the correct PIN when
making a payment. A problem where the approximate solution is best is when you 
have to improvise a meal with alternative ingredients, like running out of
something or catering for allergies and intolerances.

## 1.1-6
Counting how much you have of everything in the pantry is a problem where
everything is available before you begin (offline) to figure out how much you 
need to buy. As for something without knowing what the next input will be, loans
can change when you expect to be able to finish paying them off. Interest rates 
and wages are subject to change (online), which can make it hard to predict when
the loan will be fully paid. If a loan changes enough, people may switch
to a different provider.

# Exercises 1.2

## 1.2-1
When searching for a word in document or webpage, algorithms to find the word
are used. For example, in a document like this one, a linear scan with maybe
some skipping is used. As for the web, it would take way too long to find a page
by going through every word. Instead, matrices are used to figure out which
pages have the greatest similarity by comparing keyword vectors. One pinpoints
the exact word, whereas the other is used to determine whether the word appears
often in a page.

## 1.2-2
Values of $n$ where insertion sort beats merge sort:
```math
\begin{aligned}
&& 8n^2 &< 64n\log_2(n), n\in\mathbb{N}\\
&\iff& n &< 8\log_2(n)\\
&\iff& n &< \log_2(n^8)\\
&\implies& n&\in[2,43]\text{ by inspection}
\end{aligned}
```

## 1.2-3
Smallest value of $n$ such that $100n^2$ runs faster than $2^n$:
```math
\begin{aligned}
&& 100n^2 &< 2^n, n\in\mathbb{N}\\
&\iff& (10n)^2 &< 2^n\\
&\iff& 10n &< (\sqrt{2})^n\\
&\iff& n &< \frac{(\sqrt{2})^n}{10}\\
&\implies& n&=15\text{ by inspection}
\end{aligned}
```

# Problems

## 1.1 Comparison of running times

From Google's unit converter:

A second is $10^6\mu s$.\
A minute is $6\cdot10^7\mu s$.\
A hour is $36\cdot10^8\mu s$.\
A day is $864\cdot10^8\mu s$.\
A month is $2628\cdot10^9\mu s$.\
A year is $3154\cdot10^{10}\mu s$.\
A century is $3154\cdot10^{12}\mu s$.

| | 1 second | 1 minute | 1 hour | 1 day | 1 month | 1 year | 1 Century |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $\log_2(n)$ | $2^{10^6}$ | $2^{6\cdot10^7}$ | $2^{36\cdot10^8}$ | $2^{864\cdot10^8}$ | $2^{2628\cdot10^9}$ | $2^{3154\cdot10^{10}}$ | $2^{3154\cdot10^{12}}$ |
| $\sqrt{n}$ | $10^{12}$ | $36\cdot10^{14}$ | $1296\cdot10^{16}$ | $746496\cdot10^{16}$ | $6906384\cdot10^{18}$ | $9947716\cdot10^{20}$ | $9947716\cdot10^{24}$ |
| $n\log_2(n)$ | $62746$ | $2801417$ | $133378058$ | $2755147513$ | $72830422138$ | $797731502607$ | $68619394449811$ |
| $n^2$ | $1000$ | $7745$ | $60000$ | $293938$ | $1621110$ | $5616048$ | $56160484$ |
| $n^3$ | $100$ | $391$ | $1532$ | $4420$ | $13799$ | $31593$ | $146645$ |
| $2^n$ | $19$ | $25$ | $31$ | $36$ | $41$ | $44$ | $51$ |
| $n!$ | $9$ | $11$ | $12$ | $13$ | $15$ | $16$ | $17$ |

I filled in a bit of the table, and then I just made AI do the rest due to 
tediousness. I think 1 second to 1 hour would have been enough to illustrate 
the difference, and the exact numbers do not really matter here anyway.

Something that really stands out in this table is how $n!$ barely changes 
despite going from 1 second to 1 year of processing time. 

Note that the best time would be constant, but it does not really work in this 
table, since it would calculate any arbitrarily large $n$ in virtually no time 
at all, assuming we are thinking asymptotically here.