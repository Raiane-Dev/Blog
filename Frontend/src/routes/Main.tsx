import { Routes, Route } from 'react-router-dom';
import '../theme/app.less';

import _Header from '../components/Header';
import _Navbar from '../components/Navbar';
import _Footer from '../components/Footer';
import Home from '../views/Home';
import Ticket from '../views/Ticket';
import Create from '../views/Create';
import Login from '../views/Login';

export const isAuthenticated = () => sessionStorage.getItem('token') ? true : false;

function Main(): any
{
    return (
        <>
        <_Header />
            <Routes>
                <Route path="/" element={<Home />} />
                <Route path="/ticket/:id" element={<Ticket />} />
                <Route path="/create" element={<Create />} />
                <Route path="/login" element={<Login />} />
                <Route path="/*" element={<Home />} />
            </Routes>
        <_Footer />
        </>
    );
};

export default Main;