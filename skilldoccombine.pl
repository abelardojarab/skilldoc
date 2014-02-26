#!/usr/bin/perl -w
#
# To index an entire directory use: 
#     perl skilldoccombine.pl 
#

use strict;
use Cwd;

my $cwd = getcwd();
my @filelist = `tree -if --noreport . | grep "html" | grep -v "1.html" | grep -v "index.html"`;

# holds the name of each file
# as it is being processed.
my $file;     
my $outputFile = "";

# holds the text of the heading
# (from the anchor tag).
my $heading;   
                
# holds the last heading level
# for comparision.
my $oldLevel;   
                
# holds each line of the file 
# as it is being processed.
my $line;      
                
# used as temporary variables 
# to shorten script line widths
my $match;     
my $href;      

# holds the name of the heading 
# from the anchor tag.
my $name = "";      
                
# holds the level of the current heading.
my $newLevel;  

# First, I open an output file and print the 
# beginning of the HTML that is needed.
#
$outputFile = "fulltoc.htm";
open(OUT, ">$outputFile");
print OUT ("<HTML><HEAD><TITLE>");
print OUT ("Detailed Table of Contents for FRAT files\n");
print OUT ("</TITLE></HEAD><BODY bgcolor=\"silver\">\n");

# Now, loop through every file in the command 
# line looking for Header tags. When found, Look 
# for an Anchor tag so that the NAME attribute can 
# be used. The NAME attribute might be different
# from the actual heading.
#
# my @filelists =  split(@filelist,"\r");
print("Processing @filelist \n");
     
foreach $file (@filelist) {
    next if $file =~ m/^\.html$/i;
    print("Adding $file");
    print OUT ("<UL>\n");

    $name = $file;
    $heading = $file;
    $href = $file;
    print OUT ("<LI>");
    print OUT ("<A HREF=$href target=\"content\">");
    print OUT ("$heading</A>\n");
    print OUT ("</UL>\n");
 
}

# End the HTML document and close the output file.
#
print OUT ("</BODY></HTML>");
close(OUT);

# Fix the ugly font in source code webpages
system("find ./ -name \"*.html\" | xargs sed -i 's#font size=\"2\"#font size=\"4\"#g'");
system("find ./ -name \"*.html\" | xargs sed -i 's#)[ \t][ \t]*#) #g'");
system("find ./ -name \"*.html\" | xargs sed -i 's#)[ \t]*)#))#g'");
system("find ./ -name \"*.html\" | xargs sed -i 's#    # #g'");
