select max(salary) as secondHighestSalary from Employee where salary not in (select max(salary) from Employee);
