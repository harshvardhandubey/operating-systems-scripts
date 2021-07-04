#include &lt;stdio.h&gt;
void main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf(&quot;\n Page Replacement Policies : First In First Out (FIFO) \n&quot;);
printf(&quot;\n Enter the Number of Pages : &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\n Enter The Reference String : &quot;);
for(i=1;i&lt;=n;i++)
scanf(&quot;%d&quot;,&amp;a[i]);
printf(&quot;\n Enter the Number of Frames : &quot;);
scanf(&quot;%d&quot;,&amp;no);
for(i=0;i&lt;no;i++)
frame[i]= -1;
j=0;
printf(&quot; String\t Page Frames\n&quot;);
for(i=1;i&lt;=n;i++)
{
printf(&quot; %d\t&quot;,a[i]);
avail=0;
for(k=0;k&lt;no;k++)
if(frame[k]==a[i])
avail=1;

if (avail==0)
{
frame[j]=a[i];
j=(j+1)%no;
count++;
for(k=0;k&lt;no;k++)
printf(&quot; %d\t&quot;,frame[k]);
}
printf(&quot;\n&quot;);
}
printf(&quot;Page Fault Is %d \n&quot;,count);
}