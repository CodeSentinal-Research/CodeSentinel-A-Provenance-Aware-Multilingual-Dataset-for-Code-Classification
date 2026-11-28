function timeNeededToBuyTickets(n, tickets, k) {
    let queue = [];
    let currentTicketCount = 1;
    let time = 0;

    while (true) {
        queue.push(currentTicketCount);

        if (currentTicketCount === tickets[k]) {
            currentTicketCount = 0;
            while (queue.length > 0) {
                queue.shift();
                if (queue.length > 0) {
                    currentTicketCount++;
                    time++;
                }
            }
            break;
        } else {
            currentTicketCount++;
            time++;
        }

        if (currentTicketCount > tickets[k]) {
            currentTicketCount = 1;
        }
    }

    return time;
}