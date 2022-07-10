type 'a stack = {mutable list : 'a list};;

exception Empty;;

let create () = {list = []};;

let push x s = s.list <- x::s.list;;

let pop s = match s.list with
    | [] -> raise Empty
    | h::t -> s.list <- t; h;;

