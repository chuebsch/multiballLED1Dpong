module dcjack(){
  //  difference(){
        union(){
        rotate(90,[0,1,0])cylinder($fn=60,d=8.3,h=14);
        translate([0,-4.5,-6])cube([3,9,11]);
        translate([0,-4.5,-6])cube([14,9,6]);
        }
    rotate(90,[0,1,0])cylinder($fn=60,d=6,h=9);
   // }
}
%import("pong1.stl");
//color("red")translate([2.3,50,15])dcjack();
color("teal")
difference(){
translate([0,0,31.5])

union(){
minkowski(){
    cube([50,100,3]);
    sphere($fn=24,d=1.5);
}
translate([3,2.1,-20])cube([45,3,20]);
translate([3,100-2.1-3,-20])cube([45,3,20]);
translate([3,1.6,-18])cube([45,3,2]);
translate([3,100-1.6-3,-18])cube([45,3,2]);

translate([3,50-4.5,-20])cube([15,9,20]);
}
translate([2.3,50,15])dcjack();
}