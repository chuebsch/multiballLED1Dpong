

*cube([670,70,50]);//all
a=225;
b=100;
c=30;
w=11;
k=1000/60;    
ang=2.81;
kc=k*cos(ang);
ks=k*sin(ang);
bore=5.5;
//color("red")
/*
translate([a-20,5.9,c/2-1.8])rotate(90,[1,0,0])import("VerbinderM3.stl");
translate([a-20,b-5.9,c/2+2.2])rotate(-90,[1,0,0])import("VerbinderM3.stl");
translate([2*a-20,5.9,c/2-1.8])rotate(90,[1,0,0])import("VerbinderM3.stl");
translate([2*a-20,b-5.9,c/2+2.2])rotate(-90,[1,0,0])import("VerbinderM3.stl");*/
module pong(){
difference(){
    minkowski(){
    cube([a,b,c]);
        sphere($fn=24,d=1.5);
        }
    translate([2.1,2,0.5])
    cube([a+4,b-4,c+5]);
    translate([15,15,-1.1])cylinder(h=15,d=bore,$fn=50);
    translate([15,b-15,-1.1])cylinder(h=15,d=bore,$fn=50);
    color("teal")rotate(-ang)
        translate([-5.1,(b/2)+(w),-1.5])cube([a+5,w,1.5]);
        color("blue")translate([35,w/4,-1.5])cube([90,3.25*w,1.5]);
        translate([a,-1,-1])cube([a+5,b+5,c+5]);
        translate([k/4,(b/2)+1.5*w,-1.1])cylinder(h=15,d=bore,$fn=50);
        translate([-5,(b/2),c/2])rotate(90,[0,1,0])cylinder(h=15,d=2*bore,$fn=50);
        translate([38,3*w,-1.1])cylinder(h=15,d=bore,$fn=50);
        
translate([a+9.6/2,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a+9.6/2+9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a+9.6/2-9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a+9.6/2-2*9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);


translate([a-20,5.9,c/2-1.8])rotate(90,[1,0,0])import("VerbinderM3.stl");
translate([a-20,b-5.9,c/2+2.2])rotate(-90,[1,0,0])import("VerbinderM3.stl");
translate([2*a-20,5.9,c/2-1.8])rotate(90,[1,0,0])import("VerbinderM3.stl");
translate([2*a-20,b-5.9,c/2+2.2])rotate(-90,[1,0,0])import("VerbinderM3.stl");
        /*
    for (i=[0:14]){
    translate([k/2+i*kc,(b/2)-i*ks+1.5*w,-1.1])cylinder(h=15,d=bore,$fn=50);
        echo(i*ks,i*kc);
    }
    
    for (i=[1:5]){
        translate([30+i*k,w-w/4,-1.1])cylinder(h=15,d=bore,$fn=50);
        translate([30+i*k,2*w-w/4,-1.1])cylinder(h=15,d=bore,$fn=50);
        translate([30+i*k,3*w-w/4,-1.1])cylinder(h=15,d=bore,$fn=50);
    }
        */
}
}

//*
//rotate(-ang)color("teal")translate([-1.1,(b/2)+(w),-3.1])cube([a*3,w,2.5]);
/*
color("red")
translate([a+9.6/2,0,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.2,h=2.5*b);

translate([a+9.6/2+9.6,0,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.2,h=2.5*b,center=true);

translate([a+9.6/2-9.6,0,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.2,h=2.5*b,center=true);

translate([a+9.6/2-2*9.6,0,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.2,h=2.5*b,center=true);
*/
*difference(){
color("pink")translate([a,0,0])
    minkowski(){
    cube([a,b,c]);
        sphere($fn=24,d=1.5);
        }    
        translate([a-6,2,0.5])cube([a+20,b-4,c+5]);
        rotate(-ang)color("teal")translate([-1.1,(b/2)+(w),-1.5])cube([a*3,w,1.5]);
        
translate([a+9.6/2,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a+9.6/2+9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a+9.6/2-9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a+9.6/2-2*9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);
////
translate([2*a+9.6/2,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([2*a+9.6/2+9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([2*a+9.6/2-9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([2*a+9.6/2-2*9.6,b+5,c/2])
rotate(90,[1,0,0]) cylinder($fn=60,d=3.6,h=b+10);

translate([a-20,5.9,c/2-1.8])rotate(90,[1,0,0])import("VerbinderM3.stl");
translate([a-20,b-5.9,c/2+2.2])rotate(-90,[1,0,0])import("VerbinderM3.stl");
translate([2*a-20,5.9,c/2-1.8])rotate(90,[1,0,0])import("VerbinderM3.stl");
translate([2*a-20,b-5.9,c/2+2.2])rotate(-90,[1,0,0])import("VerbinderM3.stl");


translate([1.2*a,b/3,0.1])cylinder($fn=60,d=57,h=3);
translate([1.2*a,b/3,-5])cylinder($fn=60,d=20,h=13);
        //for (i=[13:28]){color("red")translate([k/2+i*kc,(b/2)-i*ks+1.5*w,-1.1])cylinder(h=15,d=bore,$fn=50); }
}



//  */ 
pong();
translate([3*a,b,0])rotate(180)pong();
