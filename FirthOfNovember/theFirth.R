#!/usr/bin/env Rscript
date <- Sys.Date()
string <- grep("11-5",date)
#Guy Fawkes lol
if (string == 1){ 
    print("Remember, remember, the 5th of November", quote=FALSE, file=stderr())
    print("I know of no reason, why the gunpowder treason", quote=FALSE, file=stderr())
    print("should ever be forgot", quote=FALSE, file=stderr())
}

