%单纯行算法
A=[1,-2,-2,3;2,-3,-1,1;0,0,1,0;-1,0,0,0;0,-1,0,0;0,0,-1,0;0,0,0,-1] 
b=[0;0;1;0;0;0;0]
c=[-3;5;-1;2]
x=[0;0;0;0]
J=[4,5,6,7]
y=[0,0,0,0]
z=[0;0;0;0;0;0;0]
while 1
b0=b-A*x;
i=0;
j=1;
A0=A(J,:)';
z(:)=0;
z(J)=-inv(A0)*c
k=0;
for i=1:7
if z(i)<0
k=i;
break
end
end
if k==0
break
end
for i=1:4
if J(i)==k;
y(i)=-1;
else
y(i)=0;
end
end
deltaX=inv(A0')*y'
A1=A*deltaX
a=min(b0(find(A1(:)>0))./A1(find(A1(:)>0)));
j=intersect(find(b0./A1(:)==a),find(A1(:)>0));
j=j(1);
for i=1:4
if J(i)==k;
J(i)=j;
end
end
J=sort(J)
x=x+a*deltaX;
end
x



%不可行原始对偶路径算法
A=[1,-2,-2,3;2,-3,-1,1;0,0,1,0;-1,0,0,0;0,-1,0,0;0,0,-1,0;0,0,0,-1];
b=[0;0;1;0;0;0;0];
c=[-3;5;-1;2];
x0=[0;0;0;0];
z=[1;1;1;1;1;1;1];
s0=[1;1;1;1;1;1;1];
delta=0.0001;
for j=1:100
p1=A*x0+s0-b;
d1=A'*z+c;
if norm(p1)<delta && norm(d1)<delta && dot(s0,z)<delta;
break;
end;
S=diag(s0);
Z=diag(z);
m=size(A,1);n=size(A,2);
A0=[zeros(m,m),A,eye(m);A',zeros(n,n),zeros(n,m);S,zeros(m,n),Z];
b0=[-p1;-d1;-s0.*z];
X=A0\b0;
z1=X(1:7);
x1=X(8:11);
s1=X(12:18);
p2=1;
for i=1:7
if s0(i)>0 && s1(i)<0
p2=min(p2,-s0(i)/s1(i));
end
end
d2=1;
for i=1:7
if z(i)>0 && z1(i)<0
d2=min(d2,-z(i)/z1(i));
end
end
s=((s0+p2*s1)'*(z+d2*z1))/(s0'*z);
s=s*s*s;
b0(12:18)=b0(12:18)+s*(s0'*z/m)*ones(7,1);
X=A0\b0;
z1=X(1:7);
x1=X(8:11);
s1=X(12:18);
p2=1;
for i=1:7
if s0(i)>0 && s1(i)<0
p2=min(p2,-s0(i)/s1(i));
end
end
d2=1;
for i=1:7
if z(i)>0 && z1(i)<0
d2=min(d2,-z(i)/z1(i));
end
end
x0=x0+min(1,0.99*p2)*x1;
s0=s0+min(1,0.99*p2)*s1;
z=z+min(1,0.99*d2)*z1;
end
x0