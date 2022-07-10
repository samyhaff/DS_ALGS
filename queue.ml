exception Empty;;

type 'a cell = {value : 'a; mutable previous : 'a list; mutable next : 'a list}
and 'a list = Nil | Cell of 'a cell;;

type 'a queue = {mutable head : 'a list; mutable tail : 'a list};;

let create () = {head = Nil; tail = Nil};;

let add x q =
    let c = Cell {value = x; previous = q.tail; next = Nil} in
    match q.tail with
        | Nil -> q.head <- c; q.tail <- c
        | Cell a -> a.next <- c; q.tail <- c;;

let take q = match q.head with
    | Nil -> raise Empty
    | Cell c -> match c.next with
        | Nil -> q.head <- Nil; q.tail <- Nil; c.value
        | Cell d -> d.previous <- Nil; q.head <- c.next; c.value;;

let peek q = match q.head with
    | Nil -> raise Empty
    | Cell c -> c.value;;
