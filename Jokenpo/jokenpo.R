#!/usr/bin/env Rscript

# I prefer to pass my entrys as argments in the command line
a <- commandArgs(trailingOnly=T)

if(length(a) == 0){
	entrys <-  c("s,s", "s,p", "s,r", "r,r", "r,p") 
	# default values in case no argument is passed in command lines
}else{
	entrys <- a
}

jokenpo <- function(entry){
    win_dict <- c(p="r",r="s", s="p")

    for (i in seq_along(entry)){
    	p1 <- strsplit(entry[i], split=",")[[1]][1] # player 1
    	p2 <- strsplit(entry[i], split=",")[[1]][2] # player 2

    	if (!(p1 %in% win_dict) || !(p2 %in% win_dict)) print(paste0(entry[i], ' = invalid'))
    	
    	else if (win_dict[p1] == p2) print(paste0(entry[i],' = player 1 wins'))
    	
    	else if (win_dict[p2] == p1) print(paste0(entry[i],' = player 2 wins'))
    	
    	else print(paste0(entry[i],' = tie'))
    }
}

jokenpo(entrys)
