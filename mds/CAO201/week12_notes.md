#Week 12


## Page Replacement

When you need a page that isn't in memory you have to load it in. Conversely, a page in memory has to get the boot. How do you choose?

> **The dream: last pick gets the boot**
>
>If you tag each page with the milliseconds from now till the time it will finally be called on, the one with the highest number is the obvious candidate.
> 
> * Something is wrong with this solution. What?
> * Yet it's actually useful. How?

> **Not Recently Used**
>
> Not that popular. Technically someone invited you, but she hasn't talked to you all night.
> * Class based. 
>   0: not referenced, not modified 
>   1: not referenced, modified 
> 	2: referenced, not modified
> 	3: referenced, modified
> * Random 0 class page is asked to leave.
> * Better to remove modified but unreferenced than one heavily referenced.. it has about 20ms.