clear

A=[1,-2,-2,3;2,-3,-1,1;0,0,1,0;-1,0,0,0;0,-1,0,0;0,0,-1,0;0,0,0,-1];
b=[0;0;1;0;0;0;0];
c=[-3;5;-1;2];
xx=zeros(4,1);
ss=ones(7,1);
zz=ones(7,1);

eps=0.0001;
for TOL=1:100
    rp=A*xx+ss-b;
    rd=A'*zz+c;
    if norm(rp)<eps && norm(rd)<eps && dot(ss,zz)<eps;break;end;
    S=diag(ss);
    Z=diag(zz);
    m=size(A,1);n=size(A,2);
    AA=[zeros(m,m),A,eye(m);A',zeros(n,n),zeros(n,m);S,zeros(m,n),Z];
    bb=[-rp;-rd;-ss.*zz];
    X=AA\bb;
    dza=X(1:7);
    dxa=X(8:11);
    dsa=X(12:18);
    ap=1;
    for i=1:7
        if ss(i)>0 && dsa(i)<0
            ap=min(ap,-ss(i)/dsa(i));
        end
    end
    ad=1;
    for i=1:7
        if zz(i)>0 && dza(i)<0
            ad=min(ad,-zz(i)/dza(i));
        end
    end
    s=((ss+ap*dsa)'*(zz+ad*dza))/(ss'*zz);
    s=s*s*s;
    bb(12:18)=bb(12:18)+s*(ss'*zz/m)*ones(7,1);
    X=AA\bb;
    dza=X(1:7);
    dxa=X(8:11);
    dsa=X(12:18);
    ap=1;
    for i=1:7
        if ss(i)>0 && dsa(i)<0
            ap=min(ap,-ss(i)/dsa(i));
        end
    end
    ad=1;
    for i=1:7
        if zz(i)>0 && dza(i)<0
            ad=min(ad,-zz(i)/dza(i));
        end
    end
    xx=xx+min(1,0.99*ap)*dxa;
    ss=ss+min(1,0.99*ap)*dsa;
    zz=zz+min(1,0.99*ad)*dza;
end

% xx =
% 
%     0.5000
%    -0.0000
%     1.0000
%    -0.0000