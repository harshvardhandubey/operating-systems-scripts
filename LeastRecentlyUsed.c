#include &lt;stdio.h&gt;

void main()
{
int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];
printf(&quot;\n Page Replacement Policies : Least Recently Used (LRU) \n&quot;);
printf(&quot;\n Enter Number of Pages : &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\n Enter The Reference String : &quot;);
for(i=0;i&lt;n;i++)
scanf(&quot;%d&quot;,&amp;p[i]);
printf(&quot;\n Enter Number of Frames : &quot;);
scanf(&quot;%d&quot;,&amp;f);
q[k]=p[k];
printf(&quot;\n\t%d\n&quot;,q[k]);
c++;
k++;
for(i=1;i&lt;n;i++)
{
c1=0;
for(j=0;j&lt;f;j++)
{
if(p[i]!=q[j])
c1++;

}
if(c1==f)
{
c++;
if(k&lt;f)
{
q[k]=p[i];
k++;
for(j=0;j&lt;k;j++)
printf(&quot;\t%d&quot;,q[j]);
printf(&quot;\n&quot;);
}
else
{
for(r=0;r&lt;f;r++)
{
c2[r]=0;
for(j=i-1;j&lt;n;j--)
{
if(q[r]!=p[j])
c2[r]++;
else
break;
}
}

for(r=0;r&lt;f;r++)
b[r]=c2[r];
for(r=0;r&lt;f;r++)
{
for(j=r;j&lt;f;j++)
{
if(b[r]&lt;b[j])
{
t=b[r];
b[r]=b[j];
b[j]=t;
}
}
}
for(r=0;r&lt;f;r++)
{
if(c2[r]==b[0])
q[r]=p[i];
printf(&quot;\t%d&quot;,q[r]);
}
printf(&quot;\n&quot;);
}
}
}
printf(&quot;\nPage Fault is %d \n&quot;,c);

}