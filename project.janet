(declare-project
 :name "janbox2"
 :description "Janet bindings for Termbox2"
 :url "https://github.com/dchssr/janbox2")

(declare-native
 :name "janbox2"
 :cflags ["-DTB_IMPL"]
 :source ["janbox2.c"])
