`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/01/07 16:23:13
// Design Name: 
// Module Name: data_maker
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


module data_maker(
    input [23:0] rgb_in,
    input        valid,
    output [11:0] vga_out
    );
// 0 1 2 3 4 5 6 7 | 8 9 10 11 12 13 14 15 | 16 17 18 19 20 21 22 23
assign vga_out = (valid == 1'b1)?{rgb_in[23:20],rgb_in[15:12],rgb_in[7:4]}:12'd0;
endmodule
