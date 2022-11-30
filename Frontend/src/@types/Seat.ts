type SeatProperty =
{
    id?: number|string,
    row: string|number,
    number: string|number,
    auditorium_id: string|number,
    inquiry: number,
}

const SeatPattern: SeatProperty = {
    id: "",
    row: "",
    number: "",
    auditorium_id: "",
    inquiry: 0,
}

export { type SeatProperty, SeatPattern };