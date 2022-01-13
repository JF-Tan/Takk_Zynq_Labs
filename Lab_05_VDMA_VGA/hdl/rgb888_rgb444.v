`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/01/07 21:10:30
// Design Name: 
// Module Name: rgb888_rgb444
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module rgb888_rgb444(
    input valid_in,
    input [23:0] rgb_in,
    output [11:0] vga_out
    );
assign vga_out  = (valid_in == 1'b1)?{rgb_in[23:20],rgb_in[15:12],rgb_in[7:4]}:12'd0;
endmodule
