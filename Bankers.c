#include&lt;stdio.h&gt;
int i,j,np,nr,allo[10][10],max[10][10],need[10][10],ar[10],t[10];
int a1[10][10],m1[10][10],ar1[10],n1[10][10],seq;
static int visited[20];
int issafe(int need[10][10],int ar[10],int allo[10][10],int max[10][10]);
int canbeprocessed(int x[10],int y[10],int z[10],int ar[10]);
void maxgiven();
void needgiven();
void display();
int main()
{
char choice;
printf(&quot;\n Deadlock Avoidance : Bankers Algorithm \n&quot;);
printf(&quot;\n Do you have a Need Matrix or a Maximum Matrix? (n/m) : &quot;);
scanf(&quot;%c&quot;,&amp;choice);
printf(&quot;\n Enter the Number of Processes : &quot;);
scanf(&quot;%d&quot;,&amp;np);
printf(&quot;\n Enter the Number of Resources : &quot;);
scanf(&quot;%d&quot;,&amp;nr);
printf(&quot;\n&quot;);
for(i=0;i&lt;nr;i++)
{
printf(&quot; Enter The Maximum Instance of Resource R%d : &quot;,i+1);
scanf(&quot;%d&quot;,&amp;t[i]);
}
printf(&quot;\n Enter the Allocation Matrix : \n\t&quot;);
for(i=0;i&lt;nr;i++)
printf(&quot;R%d\t&quot;,i+1);
printf(&quot;\n&quot;);
for(i=0;i&lt;np;i++)
{
printf(&quot; P%d\t&quot;,i+1);
for(j=0;j&lt;nr;j++)
{
scanf(&quot;%d&quot;,&amp;allo[i][j]);
a1[i][j]=allo[i][j];
}
}
printf(&quot;\n&quot;);
if (choice==&#39;m&#39;)
maxgiven();
else if (choice==&#39;n&#39;)
needgiven();
else
printf(&quot;\n Error!... Wrong Choice Exiting \n&quot;);
return 0;
}
int issafe(int need[][10],int ar[10],int allo[][10],int max[][10])
{

int count=0;
printf(&quot;\n Safe Sequence : &quot;);
while(count&lt;np)
{
for(i=0;i&lt;np;i++)
{
if((visited[i]==0) &amp;&amp; canbeprocessed(need[i],allo[i],max[i],ar))
{
count++;
visited[i]=1;
printf(&quot;P%d-&gt;&quot;,i+1);
break;
}
}
if(i==np)
return 0;
}
return 1;
}
int canbeprocessed(int x[],int y[],int z[],int ar[])
{
for(j=0;j&lt;nr;j++)
{
if(x[j]&gt;ar[j])
return 0;
}
for(j=0;j&lt;nr;j++)
{
ar[j]+=y[j];
y[j]=z[j]=0;
}
return 1;
}
void needgiven()
{
printf(&quot;\n Enter the Need Matrix : \n\t&quot;);
for(i=0;i&lt;nr;i++)
printf(&quot;R%d\t&quot;,i+1);
printf(&quot;\n&quot;);
for(i=0;i&lt;np;i++)
{
printf(&quot; P%d\t&quot;,i+1);
for(j=0;j&lt;nr;j++)
{
scanf(&quot;%d&quot;,&amp;need[i][j]);
n1[i][j]=need[i][j];
}
}
for(i=0;i&lt;np;i++)
{
for(j=0;j&lt;nr;j++)
max[i][j]=need[i][j] + allo[i][j];
}
display();

for(j=0;j&lt;nr;j++)
{
ar[j]=t[j];
for(i=0;i&lt;np;i++)
{
ar[j]-=allo[i][j];
ar1[j]=ar[j];
}
}
if(issafe(need,ar,allo,max))
printf(&quot;\n\n System is in Safe State! \n&quot;);
else
{
printf(&quot;NA&quot;);
printf(&quot;\n\n System is in Unsafe State! \n&quot; );
}
}

void maxgiven()
{
printf(&quot;\n Enter the Maximum Matrix : \n\t&quot;);
for(i=0;i&lt;nr;i++)
printf(&quot;R%d\t&quot;,i+1);
printf(&quot;\n&quot;);
for(i=0;i&lt;np;i++)
{
printf(&quot; P%d\t&quot;,i+1);
for(j=0;j&lt;nr;j++)
{
scanf(&quot;%d&quot;,&amp;max[i][j]);
m1[i][j]=max[i][j];
}
}
for(i=0;i&lt;np;i++)
{
for(j=0;j&lt;nr;j++)
need[i][j]=max[i][j]-allo[i][j];
}
display();
for(j=0;j&lt;nr;j++)
{
ar[j]=t[j];
for(i=0;i&lt;np;i++)
{
ar[j]-=allo[i][j];
ar1[j]=ar[j];
}
}
if(issafe(need,ar,allo,max))
printf(&quot;\n\n System is in Safe State! No Deadlock! \n\n&quot;);
else
{
printf(&quot;NA&quot;);
printf(&quot;\n\n System is in Unsafe State! Deadlock Possible! \n\n&quot;);

}
}
void display()
{
printf(&quot;\n Process\tAllocation\tMaximum\t Need\t&quot;);
for(i=0;i&lt;np;i++)
{
printf(&quot;\n P%d\t\t &quot;,i+1);
for(j=0;j&lt;nr;j++)
printf(&quot;%d &quot;,allo[i][j]);
printf(&quot;\t\t&quot;);
for(j=0;j&lt;nr;j++)
printf(&quot;%d &quot;,max[i][j]);
printf(&quot;\t\t&quot;);
for(j=0;j&lt;nr;j++)
printf(&quot;%d &quot;,need[i][j]);
}
printf(&quot;\n&quot;);
}