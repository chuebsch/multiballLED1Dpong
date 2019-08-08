a=40;
b=4;
c=4;
g=(a+2*c)/5;
f6 =1/cos(180/6);
difference(){
    minkowski(){
        cube([a,b,c]);
        cylinder(d=c,$fn=42,h=0.1);
        //scale([2,2,1])sphere(d=c/2,$fn=24,h=0.1);
    }
    for(i=[1:4]){
        translate([i*g-c,b/2,-0.1])cylinder($fn=60,d=3.3,h=30);
        translate([i*g-c,b/2,-0.1])rotate(30)cylinder($fn=6,d=5.7*f6,h=2.5);
    }
}