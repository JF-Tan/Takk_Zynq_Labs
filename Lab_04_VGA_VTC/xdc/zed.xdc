set_property PACKAGE_PIN Y9 [get_ports clk_in]
set_property IOSTANDARD LVCMOS33 [get_ports clk_in]

set_property PACKAGE_PIN Y19 [get_ports vsync_out]
set_property IOSTANDARD LVCMOS33 [get_ports vsync_out]

set_property PACKAGE_PIN AA19 [get_ports hsync_out]
set_property IOSTANDARD LVCMOS33 [get_ports hsync_out]

set_property PACKAGE_PIN V20 [get_ports {vga_out[8]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[8]}]
set_property PACKAGE_PIN U20 [get_ports {vga_out[9]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[9]}]
#
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[10]}]
set_property PACKAGE_PIN V18 [get_ports {vga_out[11]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[11]}]
# 0 1 2 3| 4 5 6 7 | 8 9 10 11
set_property PACKAGE_PIN AB22 [get_ports {vga_out[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[4]}]
set_property PACKAGE_PIN AA22 [get_ports {vga_out[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[5]}]
set_property PACKAGE_PIN AB21 [get_ports {vga_out[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[6]}]
set_property PACKAGE_PIN AA21 [get_ports {vga_out[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[7]}]

set_property PACKAGE_PIN Y21 [get_ports {vga_out[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[0]}]
set_property PACKAGE_PIN Y20 [get_ports {vga_out[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[1]}]
set_property PACKAGE_PIN AB20 [get_ports {vga_out[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[2]}]
set_property PACKAGE_PIN AB19 [get_ports {vga_out[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {vga_out[3]}]



set_property PACKAGE_PIN V19 [get_ports {vga_out[10]}]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets clk]
