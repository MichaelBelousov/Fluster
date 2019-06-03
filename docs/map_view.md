
# map view

given an iterator and a function, produce an iterable

```Fluster
people = {{age=5,name="mike"}, {age=10,name="john"}}
ages = map_view<people, p=>p.age>;
```

